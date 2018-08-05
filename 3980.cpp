#include <iostream>
#include <algorithm>
using namespace std;

int c;
int r;
int s[11][11], m;

void dfs(int b, int p) {
	if (r == 11)
		m = max(m, p);
	else {
		for (int i = 0; i < 11; i++) {
			if (!s[i][r] || (b & (1 << i)))
				continue;
			dfs((b | (1 << i)), p + s[i][r++]);
			r--;
		}
	}
}

int main() {
	scanf("%d", &c);
	while (c--) {
		m = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++)
				scanf("%d", &s[i][j]);
		}
		for (int i = 0; i < 11; i++) {
			if (!s[i][r])
				continue;
			dfs(1 << i, s[i][r++]);
			r--;
		}
		printf("%d\n", m);
	}
	return 0;
}