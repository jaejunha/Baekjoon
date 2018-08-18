#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h;
bool b[31][11];
bool f;
int sol = 4;

bool check(bool t[31][11]) {
	for (int i = 1, p; i <= n; i++) {
		p = i;
		for (int j = 1; j <= h; j++) {
			if (p == 1) {
				if (t[j][p])
					p++;
			}
			else if (p == n) {
				if (t[j][p - 1])
					p--;
			}
			else {
				if (t[j][p])
					p++;
				else if (t[j][p - 1])
					p--;
			}
		}
		if (p != i)
			return false;
	}
	return true;
}

void dfs(int x, int y, bool t[31][11]) {
	if (sol <= x)
		return;
	bool c[31][11];
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j <= n; j++)
			c[i][j] = t[i][j];
	}

	for (int i = 1; i <= h; i++) {
		if (i < y)
			continue;
		for (int j = 1; j < n; j++) {
			if (c[i][j - 1] || c[i][j] || c[i][j + 1])
				continue;
			c[i][j] = true;
			if (((m + x) % 2 == 0) && check(c)) {
				sol = min(sol, x);
				return;
			}
			if (x < 3)
				dfs(x + 1, i, c);
			c[i][j] = false;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0, x, y; i < m; i++) {
		scanf("%d%d", &x, &y);
		b[x][y] = true;
	}
	if ((m % 2 == 0) && check(b)) {
		printf("0");
		return 0;
	}
	dfs(1, 1, b);
	if (sol == 4)
		printf("-1");
	else
		printf("%d", sol);

	return 0;
}