#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int p[1001];
int dp[1001];
int answer;
int dfs(int s) {
	if (s == 0)
		return 0;
	if (s == 1)
		return p[1];
	int &ret = dp[s];
	if (ret)
		return ret;
	for (int i = 1, t; i <= s; i++) {
		t = p[i];
		if (s > i)
			t += dfs(s - i);
		ret = max(ret, t);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	dfs(n);
	printf("%d", dp[n]);
	return 0;
}