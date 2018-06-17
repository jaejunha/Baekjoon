#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[502];
long long dp[502][502];

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &a[i + 1]);

	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= n + 1; j++)
			dp[i][j] = 99999999999999;


	for (int i = 1; i <= n + 1; i++)
		dp[i][i] = 0;

	for (int i = 1; i <= n; i++)
		dp[i][i + 1] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; i + j <= n + 1; j++) {
			for (int k = j + 1; k < i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k][i + j] + a[j] * a[k] * a[i + j]);
		}
	}
	printf("%lld", dp[1][n + 1]);

	return 0;
}