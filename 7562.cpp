#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int l, t, s;
bool v[301][301];
int dx[] = { -2,-2,1,-1,2,2,1,-1 };
int dy[] = { 1,-1,2,2,1,-1,-2,-2 };
P a, b;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &l);
		s = l*l;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++)
				v[i][j] = false;
		}
		scanf("%d%d", &a.first, &a.second);
		scanf("%d%d", &b.first, &b.second);
		queue<pair<P, int>> q;
		q.push({ a,0 });
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int c = q.front().second;
			q.pop();
			if (!v[x][y])
				v[x][y] = true;
			else
				continue;
			if (x == b.first && y == b.second) {
				s = min(s, c);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int px = x + dx[i];
				int py = y + dy[i];
				if (px < 0 || py < 0 || px >= l || py >= l)
					continue;
				if (v[px][py])
					continue;
				q.push({ { px,py }, c + 1 });
			}
		}
		printf("%d\n", s);
	}
	return 0;
}