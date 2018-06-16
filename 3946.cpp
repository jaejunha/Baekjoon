/* reference: https://github.com/wowoto9772/Hungry-Algorithm/tree/master/BOJ/3946 */
#include <cstdio>
#include <algorithm>
using namespace std;
int t, n;
double a, b, c;
double dp[1001][1001];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lf%lf", &n, &a, &b);
		c = 1.0 - a - b;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0.0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = a * dp[i - 1][j + 1] + b * ((j > 0) ? dp[i - 1][j - 1] : dp[i - 1][0] + 1) + c * dp[i - 1][j];

		printf("%.4lf\n", dp[n][0]);
	}
	return 0;
}
