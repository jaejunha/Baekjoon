#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int dp[1001][1001], a[1001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i][i] = max(dp[i][i], dp[i - 1][j] + 1);
				dp[i][j] = dp[i - 1][j];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++)
		m = max(m, dp[n][i]);
	printf("%d", m);
	return 0;
}