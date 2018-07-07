/* reference: http://hsp1116.tistory.com/40 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int w[16][16];
int b[17][65536];
typedef pair<int, int> P;

int dfs(int x, int v) {
	if (v == (1 << n) - 1)
		return w[x][0];

	int &ret = b[x][v];
	if (ret)
		return ret;
	ret = 17000000;
	for (int i = 0; i < n; i++) {
		if (v&(1 << i))
			continue;
		if (!w[x][i])
			continue;
		ret = min(ret, dfs(i, v | (1 << i)) + w[x][i]);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);
	}

	printf("%d", dfs(0, 1));
	return 0;
}