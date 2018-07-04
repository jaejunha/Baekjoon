#include <iostream>
#include <algorithm>
using namespace std;
int r, c;
int n;
char s[25][25];
bool b[26];
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int answer = 1;
void dfs(pair<int, int> p) {
	for (int i = 0, pr, pc; i < 4; i++) {
		pr = p.first + dr[i];
		pc = p.second + dc[i];
		if (pr < 0 || pr >= r || pc < 0 || pc >= c)
			continue;
		if (b[s[pr][pc] - 'A'])
			continue;

		n++;
		b[s[pr][pc] - 'A'] = true;
		dfs({ pr,pc });
		answer = max(answer, n);
		b[s[pr][pc] - 'A'] = false;
		n--;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> s[i];
	b[s[0][0] - 'A'] = true;

	for (int i = 0, pr, pc; i < 4; i++) {
		pr = dr[i];
		pc = dc[i];
		if (pr < 0 || pr >= r || pc < 0 || pc >= c)
			continue;
		if (s[pr][pc] == s[0][0])
			continue;
		n = 2;
		b[s[pr][pc] - 'A'] = true;
		dfs({ pr,pc });
		answer = max(answer, n);
		b[s[pr][pc] - 'A'] = false;
	}
	printf("%d\n", answer);
	return 0;
}