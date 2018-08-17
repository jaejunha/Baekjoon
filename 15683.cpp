#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct P {int x, y, d;}P;

vector<P> v[6];
int n, m;
int a[9][9];
int s = 64;
void paint(int b[9][9]) {
	int c[9][9];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = b[i][j];

	if (v[1].size()) {
		int dx[] = { 0,0,1,-1 };
		int dy[] = { 1,-1,0,0 };
		for (P p : v[1]) {
			int px = p.x + dx[p.d];
			int py = p.y + dy[p.d];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[p.d];
				py += dy[p.d];
			}
		}
	}
	if (v[2].size()) {
		int dx[] = { 0,1 };
		int dy[] = { 1,0 };
		for (P p : v[2]) {
			int px = p.x + dx[p.d];
			int py = p.y + dy[p.d];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[p.d];
				py += dy[p.d];
			}
		}
		for (P p : v[2]) {
			int px = p.x - dx[p.d];
			int py = p.y - dy[p.d];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px -= dx[p.d];
				py -= dy[p.d];
			}
		}
	}

	if (v[3].size()) {
		int dx[] = { 0,1,0,-1 };
		int dy[] = { 1,0,-1,0, };
		for (P p : v[3]) {
			int px = p.x + dx[p.d];
			int py = p.y + dy[p.d];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[p.d];
				py += dy[p.d];
			}
		}
		for (P p : v[3]) {
			int px = p.x + dx[(p.d + 1) % 4];
			int py = p.y + dy[(p.d + 1) % 4];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[(p.d + 1) % 4];
				py += dy[(p.d + 1) % 4];
			}
		}
	}

	if (v[4].size()) {
		int dx[] = { 0,1,0,-1 };
		int dy[] = { 1,0,-1,0, };
		for (P p : v[4]) {
			int px = p.x + dx[p.d];
			int py = p.y + dy[p.d];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[p.d];
				py += dy[p.d];
			}
		}
		for (P p : v[4]) {
			int px = p.x + dx[(p.d + 1) % 4];
			int py = p.y + dy[(p.d + 1) % 4];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[(p.d + 1) % 4];
				py += dy[(p.d + 1) % 4];
			}
		}
		for (P p : v[4]) {
			int px = p.x + dx[(p.d + 2) % 4];
			int py = p.y + dy[(p.d + 2) % 4];
			while (1) {
				if (px > n || py > m || px < 1 || py < 1 || c[px][py] == 6)
					break;
				if (!c[px][py])
					c[px][py] = 9;
				px += dx[(p.d + 2) % 4];
				py += dy[(p.d + 2) % 4];
			}
		}
	}

	int z = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!c[i][j])
				z++;
		}
	}
	s = min(s, z);
}
void dfs(int x, int y) {
	if (x == 5)
		paint(a);
	else {
		if (v[x].size() > y) {
			int length = ((x == 2) ? 2 : 4);
			for (int i = 0; i < length; i++) {
				v[x][y].d = i;
				dfs(x, y + 1);
			}
		}
		else
			dfs(x + 1, 0);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] >= 1 && a[i][j] <= 5)
				v[a[i][j]].push_back({ i,j,0 });
		}
	}

	if (v[5].size()) {
		int dx[] = { 0,0,1,-1 };
		int dy[] = { 1,-1,0,0 };
		for (P p : v[5]) {
			for (int i = 0; i < 4; i++) {
				int px = p.x + dx[i];
				int py = p.y + dy[i];
				while (1) {
					if (px > n || py > m || px < 1 || py < 1 || a[px][py] == 6)
						break;
					if (!a[px][py])
						a[px][py] = 9;
					px += dx[i];
					py += dy[i];
				}
			}
		}
	}
	dfs(1, 0);
	printf("%d", s);
	return 0;
}