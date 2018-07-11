#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n, m, l, s;
int mx, mn = 1000000;
int a[1001][1001];
int dx[] = { 0,0,2,-2 };
int dy[] = { 2,-2,0,0 };
int ex[] = { 0,0,1,-1 };
int ey[] = { 1,-1,0,0 };
bool v[1001][1001];
queue<P> q;
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1, x, y, z, w; i <= l; i++) {
		scanf("%d%d%d%d", &x, &y, &z, &w);
		if (x == z) {
			for (int j = 2 * y; j <= 2 * w; j++)
				a[2 * x][j] = 1;
			for (int j = 2 * w; j <= 2 * y; j++)
				a[2 * x][j] = 1;
		}
		else {
			for (int j = 2 * x; j <= 2 * z; j++)
				a[j][2 * y] = 1;
			for (int j = 2 * z; j <= 2 * x; j++)
				a[j][2 * y] = 1;
		}
	}
	for (int i = 1, x, y; i < 2 * n + 1; i += 2) {
		for (int j = 1; j < 2 * m + 1; j += 2) {
			if (!v[i][j]) {
				s = 0;
				q.push({ i,j });
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (v[x][y])
						continue;
					v[x][y] = true;
					s++;
					for (int i = 0, px, py, qx, qy; i < 4; i++) {
						px = x + dx[i];
						py = y + dy[i];
						qx = x + ex[i];
						qy = y + ey[i];
						if (px >= 2 * n || py >= 2 * m || px <= 0 || py <= 0)
							continue;
						if (a[qx][qy])
							continue;
						if (!v[px][py])
							q.push({ px,py });
					}
				}
				mx = max(mx, s);
				mn = min(mn, s);
			}
		}
	}
	printf("%d\n%d", mx, mn);
	return 0;
}