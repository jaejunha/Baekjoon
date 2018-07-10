#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
int n, m, t, s;
int mx;
int a[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool v[501][501];
queue<P> q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j])
				t++;
		}
	}
	if (t == n*m)
		printf("1\n%d", n*m);
	else if (t == 0)
		printf("0\n0");
	else {
		t = 0;
		for (int i = 1, x, y; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] && !v[i][j]) {
					t++;
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
						for (int i = 0, px, py; i < 4; i++) {
							px = x + dx[i];
							py = y + dy[i];
							if (px > n || py > m || px <= 0 || py <= 0)
								continue;
							if (a[px][py] && !v[px][py])
								q.push({ px,py });
						}
					}
					mx = max(mx, s);
				}
			}
		}
		printf("%d\n%d", t, mx);
	}
	return 0;
}