#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int t[16], p[16];
int dp[16];

int dfs(int x) {
	int m = 0;
	if (x > n)
		return 0;
	for (int i = x; i <= n; i++) {
		if (i + t[i] > n + 1)
			continue;
		m = max(m, p[i] + dfs(i + t[i]));
	}
	return m;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &p[i]);
	for (int i = 1; i <= n; i++)
		m = max(m, dfs(i));
	printf("%d", m);
	return 0;
}