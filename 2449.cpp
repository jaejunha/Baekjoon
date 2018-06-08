/* reference: http://blog.naver.com/PostView.nhn?blogId=allkanet72&logNo=220954082374&redirect=Dlog&widgetTypeCall=true */
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int a[201];
int dp[201][201];

int sol(int l, int r) {
	if (l == r)
		return 0;
	if (a[l] == a[l + 1])
		return sol(l + 1, r);
	if (a[r] == a[r - 1])
		return sol(l, r - 1);

	if (dp[l][r])
		return dp[l][r];

	dp[l][r] = sol(l + 1, r) + 1;

	for (int i = l + 1; i <= r; i++) {
		if (a[i] == a[l])
			dp[l][r] = min(sol(l + 1, i - 1) + sol(i, r) + 1, dp[l][r]);
	}

	return dp[l][r];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; scanf("%d", &a[i++]));

	printf("%d", sol(1, n));
	return 0;
}