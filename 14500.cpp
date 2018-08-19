#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s;
int a[501][501];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 3; j++)
			s = max(s, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3]);
	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n - 3; i++)
			s = max(s, a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j]);
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++)
			s = max(s, a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1]);
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			s = max(s, a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]);
			s = max(s, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]);

			s = max(s, a[i][j + 1] + a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1]);
			s = max(s, a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2]);

			s = max(s, a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]);
			s = max(s, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j]);

			s = max(s, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2]);
			s = max(s, a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2]);
		}
	}

	for (int j = 1; j <= m - 1; j++) {
		for (int i = 1; i <= n - 2; i++) {
			s = max(s, a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1]);
			s = max(s, a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j]);

			s = max(s, a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1]);
			s = max(s, a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j]);

			s = max(s, a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1]);
			s = max(s, a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1]);

			s = max(s, a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1]);
			s = max(s, a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j]);
		}
	}

	printf("%d", s);
	return 0;
}