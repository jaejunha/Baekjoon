#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1001][1001];
int dp[1001][1001];
int dp2[1001][1001];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}

	for (int j = 1; j <= m; j++)
		dp[1][j] = dp[1][j - 1] + a[1][j];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + a[i][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; j--) {
			if (j == m)
				dp2[i][j] = dp[i - 1][j] + a[i][j];
			else
				dp2[i][j] = max(dp[i - 1][j], dp2[i][j + 1]) + a[i][j];
		}
		for (int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i][j], dp2[i][j]);
	}

	printf("%d", dp[n][m]);
	return 0;
}