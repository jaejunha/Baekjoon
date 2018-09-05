#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct {
	int x, y, z, t;
}P;

int l, r, c, s;
char a[31][31][31];
int d[31][31][31];
P p;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int main() {
	while (true) {
		scanf("%d %d %d", &l, &r, &c);
		if (!l && !r && !c)
			return 0;
		scanf("%c", &s);
		queue<P> q;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				if (j != 1)
					scanf("%c", &s);
				for (int k = 1; k <= c; k++) {
					scanf("%c", &a[i][j][k]);
					if (a[i][j][k] == 'S') {
						p.x = i;
						p.y = j;
						p.z = k;
						p.t = 0;
						q.push(p);
					}
				}
			}
			scanf("%c", &s);
			scanf("%c", &s);
		}

		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++)
					d[i][j][k] = 0;
			}
		}
		s = 9999999;

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			int t = q.front().t;

			q.pop();
			if (a[x][y][z] == 'E') {
				s = min(s, t);
				break;
			}
			for (int i = 0; i < 6; i++) {
				int px = x + dx[i];
				int py = y + dy[i];
				int pz = z + dz[i];
				if (px<1 || py<1 || pz<1 || px>l || py>r || pz>c)
					continue;
				if (a[px][py][pz] == '#')
					continue;
				if (!d[px][py][pz] || (d[px][py][pz] > t + 1)) {
					d[px][py][pz] = t + 1;
					p.x = px;
					p.y = py;
					p.z = pz;
					p.t = t + 1;
					q.push(p);
				}
			}
		}
		if (s == 9999999)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", s);
	}
	return 0;
}