#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int dp[1001];

int dfs(int x) {
	if (x <= 1)
		return 0;
	int &ret = dp[x];
	if (ret)
		return ret;
	ret = 123456;
	for (int i = 1; i <= x; i++) {
		if (a[x - i] >= i)
			ret = min(ret, dfs(x - i) + 1);
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(n);
	printf("%d", dp[n] == 123456 ? -1 : dp[n]);
	return 0;
}