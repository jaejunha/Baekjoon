/* reference: https://github.com/leeho203/Online-Judge-Solution/blob/master/2560%20%EC%A7%9A%EC%8B%A0%EB%B2%8C%EB%A0%88.java */
#include<cstdio>
#include<algorithm>
using namespace std;

int a, b, d, n;
int dp[1000001];
int main() {
	scanf("%d%d%d%d", &a, &b, &d, &n);
	for (int i = 0; i < a; i++)
		dp[i] = 1;
	for (int i = a; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - a] - ((i < b) ? 0 : dp[i - b]) + 1000) % 1000;
	printf("%d", (dp[n] - ((n >= d) ? dp[n - d] : 0) + 1000) % 1000);
	return 0;
}