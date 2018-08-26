/* reference: http://lmcoa15.tistory.com/28 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t;
int p[101][101];
bool b[101][101];
vector<int> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs(int y, int x) {
	int s = 1;
	for (int i = 0; i < 4; i++) {
		int py = y + dy[i];
		int px = x + dx[i];
		if (py < 0 || px < 0 || py >= m || px >= n)
			continue;
		if (p[py][px])
			continue;
		if (b[py][px])
			continue;
		b[py][px] = true;
		s += dfs(py, px);
	}
	return s;
}

int main() {
	scanf("%d%d%d", &m, &n, &t);
	while (t--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				p[j][i] = 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j])
				continue;
			if (p[i][j])
				continue;
			b[i][j] = true;
			v.push_back(dfs(i, j));
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i : v)
		printf("%d ", i);

	return 0;
}