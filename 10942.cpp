#include <iostream>
using namespace std;

int n, m;
int a[2001];
int dp[2001][2001];

int check(int l, int r) {
	if (l >= r)
		return 1;
	int &ret = dp[l][r];
	if (ret != -1)
		return ret;
	if (check(l + 1, r - 1) && a[l] == a[r])
		ret = 1;
	else
		ret = 0;
	check(l + 1, r);
	check(l, r - 1);

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i][i] = 1;
	}
	check(1, n);
	scanf("%d", &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", dp[x][y]);
	}
	return 0;
}