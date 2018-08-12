#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n;
int a[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int mx;
int s;

void dfs(int l) {
	bool v[101][101];
	int c = 0;
	queue<P> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			v[i][j] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] > l && !v[i][j]) {
				c++;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (v[x][y])
						continue;
					v[x][y] = true;
					for (int i = 0; i < 4; i++) {
						int px = x + dx[i];
						int py = y + dy[i];
						if (px > n || py > n || px < 1 || py < 1)
							continue;
						if (v[px][py])
							continue;
						if (a[px][py] > l)
							q.push({ px, py });
					}
				}
			}
		}
	}
	s = max(s, c);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			mx = max(mx, a[i][j]);
		}
	}

	for (int i = 0; i <= mx; i++)
		dfs(i);

	printf("%d", s);
	return 0;
}