/* reference: http://hanstemcell.tistory.com/entry/%EB%B0%B1%EC%A4%80%EB%8B%A4%EB%A6%AC-%EB%A7%8C%EB%93%A4%EA%B8%B0 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> P;

int n;
int a[101][101], b[101][101], c;
bool d[101][101];
queue<P> q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<P> v;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!a[i][j])
				continue;
			if (b[i][j])
				continue;
			q.push({ i,j });
			c++;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (b[x][y])
					continue;
				b[x][y] = c;
				for (int k = 0; k < 4; k++) {
					int px = x + dx[k];
					int py = y + dy[k];
					if (px < 1 || py < 1 || px > n || py > n)
						continue;
					if (b[px][py])
						continue;
					if (!a[px][py]) {
						if (!d[x][y]) {
							v.push_back({ x,y });
							d[x][y] = true;
						}
						continue;
					}
					q.push({ px,py });
				}
			}
		}
	}
	int s = 100000;
	for (P p : v) {
		for (P t : v) {
			if (p == t)
				continue;
			if (b[p.first][p.second] == b[t.first][t.second])
				continue;
			s = min(s, abs(p.first - t.first) + abs(p.second - t.second));
		}
	}
	printf("%d", s - 1);
	return 0;
}