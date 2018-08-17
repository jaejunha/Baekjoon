#include <iostream>
using namespace std;
int n, c;
int a[101], s[101], b[101];

void dfs(int x, int y, int m) {
	if (x == 3) {
		int d[2][3];
		d[0][0] = y / 100;
		d[0][1] = (y % 100) / 10;
		d[0][2] = (y % 10);
		for (int i = 1, j, k; i <= n; i++) {
			j = 0;
			d[1][0] = a[i] / 100;
			d[1][1] = (a[i] % 100) / 10;
			d[1][2] = a[i] % 10;
			if (d[1][0] == d[0][0])
				j++;
			if (d[1][1] == d[0][1])
				j++;
			if (d[1][2] == d[0][2])
				j++;

			if (j != s[i])
				return;

			j = 0;
			j = j | (1 << d[1][0] - 1);
			j = j | (1 << d[1][1] - 1);
			j = j | (1 << d[1][2] - 1);
			j = j & m;
			k = 0;
			while (j) {
				if (j & 1)
					k++;
				j = j >> 1;
			}
			if (k != (b[i] + s[i]))
				return;
		}
		c++;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (m & (1 << (i - 1)))
				continue;
			dfs(x + 1, y * 10 + i, m | (1 << (i - 1)));
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i], &s[i], &b[i]);
	dfs(0, 0, 0);
	printf("%d", c);
	return 0;
}