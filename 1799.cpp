/* reference: http://saurus2.tistory.com/entry/1799-%EB%B0%B1%EC%A4%80-%EB%B9%84%EC%88%8D-%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, ret, ans;
int v[11][11];
bool chess[21], cross[21];
void dfs(int x, int y, int z, int m) {
	int a = x;
	int b = y;
	ret = max(ret, z);
	if (b > n) {
		a++;
		if (!m)
			b = 2 - (a % 2);
		else
			b = (a % 2) + 1;
	}
	if (a > n)
		return;
	if (!chess[a + b] && !cross[10 + a - b] && v[a][b]) {
		chess[a + b] = true;
		cross[10 + a - b] = true;
		dfs(a, b + 2, z + 1, m);
		chess[a + b] = false;
		cross[10 + a - b] = false;
	}
	dfs(a, b + 2, z, m);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &v[i][j]);
	}

	dfs(1, 1, 0, 0);
	ans += ret;
	ret = 0;
	dfs(1, 2, 0, 1);
	ans += ret;

	printf("%d", ans);
	return 0;
}