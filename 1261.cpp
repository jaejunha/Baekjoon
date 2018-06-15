#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> C;

int n, m;
int d[101][101];
int c[101][101];
bool b[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

priority_queue<C, vector<C>, greater<C>> q;

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 99999999;
			scanf("%1d", &c[i][j]);
		}
	}

	d[1][1] = 0;
	q.push({ 0,{ 1,1 } });
	int x, y, px, py, l;
	while (!q.empty()) {
		x = q.top().second.first;
		y = q.top().second.second;
		l = q.top().first;
		q.pop();
		if (b[y][x])
			continue;
		else
			b[y][x] = true;
		for (int i = 0; i < 4; i++) {
			px = x + dx[i];
			py = y + dy[i];
			if (px > m || py > n || px < 1 || py < 1)
				continue;
			if (b[py][px])
				continue;
			if (d[py][px] > l + c[py][px]) {
				d[py][px] = l + c[py][px];
				q.push({ d[py][px],{ px,py } });
			}
		}
	}

	printf("%d", d[n][m]);
	return 0;
}