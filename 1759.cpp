#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;
int s;
char a[16];

bool check(char v) {
	if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
		return true;
	else
		return false;
}

void back(int i, vector<char> str, int v, int u) {
	if (s == l) {
		if (u >= 2 && v >= 1) {
			for (char ch : str)
				printf("%c", ch);
			printf("\n");
		}
	}
	else {
		for (int j = i + 1; j < c; j++) {
			vector<char> sub = str;
			sub.push_back(a[j]);
			s++;
			if (check(a[j]))
				back(j, sub, v + 1, u);
			else
				back(j, sub, v, u + 1);
		}
	}
	s--;
}

int main() {
	scanf("%d%d", &l, &c);
	char t;
	int i = 0;
	while (1) {
		scanf("%c", &t);
		if (t >= 'a' && t <= 'z')
			a[i++] = t;
		if (i == c)
			break;
	}
	sort(a, a + c);
	for (int i = 0; i < c; i++) {
		vector<char> str;
		str.push_back(a[i]);
		s = 1;
		if (check(a[i]))
			back(i, str, 1, 0);
		else
			back(i, str, 0, 1);
	}
	return 0;
}