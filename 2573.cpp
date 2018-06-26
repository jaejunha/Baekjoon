#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, c;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int a[301][301], b[301][301];
int answer;
queue<pair<pair<int, int>, int>> q, p;

int count() {
	int ret = 0;
	bool v[301][301];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			v[i][j] = false;
	}
	while (!p.empty())	p.pop();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && !v[i][j]) {
				ret++;
				p.push({ { j,i },0 });

				int x, y, px, py;
				while (!p.empty()) {
					x = p.front().first.first;
					y = p.front().first.second;
					p.pop();
					if (v[y][x])
						continue;
					v[y][x] = true;
					for (int i = 0; i < 4; i++) {
						px = x + dx[i];
						py = y + dy[i];
						if (px < 1 || px > m || py < 1 || py > n)
							continue;
						if (v[py][px])
							continue;
						if (a[py][px])
							p.push({ { px,py },0 });
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) {
				q.push({ { j,i },0 });
				c++;
			}
		}
	}
	if (q.size() == 0 || q.size() == n*m) {
		printf("0");
		return 0;
	}
	int x, y, px, py, t;
	while ((t = count()) < 2) {
		if (t == 0) {
			printf("0");
			return 0;
		}
		for (int i = 1; i <= c; i++) {
			x = q.front().first.first;
			y = q.front().first.second;
			t = q.front().second;
			q.pop();
			answer = max(answer, t);
			if (a[y][x] == 0)
				continue;
			for (int i = 0; i < 4; i++) {
				px = x + dx[i];
				py = y + dy[i];
				if (px < 1 || px > m || py < 1 || py > n)
					continue;
				if (a[py][px] <= 0)
					b[y][x]--;
			}
			if (a[y][x] > 0)
				q.push({ { x, y },t + 1 });
		}
		c = q.size();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				a[i][j] = max(a[i][j] + b[i][j], 0);
				b[i][j] = 0;
			}
		}
	}

	printf("%d", answer + 1);
	return 0;
}