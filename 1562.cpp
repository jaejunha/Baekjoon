/* reference: http://wookje.dance/2018/01/07/boj-1562-%EA%B3%84%EB%8B%A8-%EC%88%98/ */
#include <iostream>
using namespace std;

int n;
long long dp[101][10][1024];
long long s;

long long dfs(int v, int l, int c) {
	if (c < 0 || c > 9)
		return 0;
	if (l == n) {
		if (v == ((1 << 10) - 1))
			return 1;
		else
			return 0;
	}

	long long &ret = dp[l][c][v];
	if (ret != -1)
		return ret;

	ret = (dfs(v | (1 << (c - 1)), l + 1, c - 1) + dfs(v | (1 << (c + 1)), l + 1, c + 1)) % 1000000000;
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 1024; k++)
				dp[i][j][k] = -1;
	for (int i = 1; i <= 9; i++) {
		s = (s + dfs(1 << i, 1, i)) % 1000000000;
	}
	printf("%lld", s);
	return 0;
}