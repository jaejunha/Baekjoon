#include <cstdio>
using namespace std;

int w, h, c;
int a[51][51];
bool b[51][51];
int dx[] = { 0,1,1,1,0,-1,-1,-1 }, dy[] = { 1,1,0,-1,-1,-1,0,1 };
void search(int x, int y) {
	b[x][y] = true;
	for (int i = 0, px, py; i < 8; i++) {
		px = x + dx[i];
		py = y + dy[i];
		if (px<1 || px>w || py<1 || py>h)
			continue;
		if (!b[px][py] && a[px][py])
			search(px, py);
	}
}

int main() {
	while (1) {
		scanf("%d%d", &h, &w);
		if (!w && !h)
			break;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				b[i][j] = false;
				scanf("%1d", &a[i][j]);
			}
		}

		c = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (!b[i][j] && a[i][j]) {
					c++;
					search(i, j);
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}