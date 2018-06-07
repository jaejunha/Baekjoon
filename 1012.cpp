#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;
bool a[50][50], b[50][50];
queue<P> q;
vector<P> v;

int t, w, h, k, l;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d%d", &w, &h, &k);
		for (int i = 1, x, y; i <= k; i++) {
			scanf("%d%d", &x, &y);
			v.push_back({ x,y });
			a[y][x] = true;
		}

		int x, y;
		for (auto it : v) {
			if (b[it.second][it.first])
				continue;
			else {
				l++;
				q.push({ it.first, it.second });
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (b[y][x])
						continue;
					b[y][x] = true;

					for (int i = 0, px, py; i < 4; i++) {
						px = x + dx[i];
						py = y + dy[i];
						if (px >= w || px < 0 || py >= h || py < 0)
							continue;
						if (b[py][px])
							continue;
						if (!a[py][px])
							continue;
						q.push({ px,py });
					}
				}
			}
		}

		printf("%d\n", l);

		if (t) {
			l = 0;
			v.clear();
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					a[i][j] = false;
					b[i][j] = false;
				}
			}
		}
	}
	return 0;
}