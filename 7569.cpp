#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct C {
	int x, y, z;
};

int a[101][101][101];
bool b[101][101][101];
int m, n, h;
int remain;
queue<pair<C, int>> q;

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int answer;

int main() {

	scanf("%d %d %d", &m, &n, &h);
	C c;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf("%d", &a[i][j][k]);
				if (a[i][j][k] == 0)
					remain++;
				else if (a[i][j][k] == 1) {
					c.x = k;
					c.y = j;
					c.z = i;
					q.push({ c,0 });
				}
			}
		}
	}

	if (remain == 0) {
		printf("0");
		return 0;
	}

	for (int j, x, y, z, px, py, pz; !q.empty();) {
		j = q.front().second;
		z = q.front().first.z;
		y = q.front().first.y;
		x = q.front().first.x;
		a[z][y][x] = 1;
		q.pop();

		if (b[z][y][x])
			continue;
		else
			b[z][y][x] = true;

		answer = max(answer, j);

		for (int l = 0; l < 6; l++) {
			px = x + dx[l];
			py = y + dy[l];
			pz = z + dz[l];
			if (px > m || px < 1 || py > n || py < 1 || pz > h || pz < 1)
				continue;
			if (a[pz][py][px] == 0) {
				c.x = px;
				c.y = py;
				c.z = pz;
				q.push({ c,j + 1 });
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++)
				if (a[i][j][k] == 0) {
					printf("-1");
					return 0;
				}
		}
	}
	printf("%d", answer);

	return 0;
}