/* reference: http://looview.tistory.com/40 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1001][1001];
int dp[1001][1001];
int dx[] = { 1,1,0 };
int dy[] = { 0,1,1 };

int dfs(int x, int y) {
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 3; i++) {
		int px = x + dx[i];
		int py = y + dy[i];
		if (px > n || py > m || px < 1 || py < 1)
			continue;
		ret = max(ret, dfs(px, py) + a[x][y]);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d", dfs(1, 1) + a[n][m]);
	return 0;
}