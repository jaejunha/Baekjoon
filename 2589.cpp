/* reference: http://lmcoa15.tistory.com/44 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct P {
	int x, y;
}P;

int m, n, s;
char a[51][51];
int d[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<P> p;

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%c", &s);
		for (int j = 1; j <= n; j++)
			scanf("%c", &a[i][j]);
	}

	s = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 'W')
				continue;
			for (int k = 1; k <= m; k++) {
				for (int l = 1; l <= n; l++)
					d[k][l] = 0;
			}
			p.push({ i,j });
			while (!p.empty()) {
				int x = p.front().x;
				int y = p.front().y;
				p.pop();
				for (int k = 0; k < 4; k++) {
					int px = x + dx[k];
					int py = y + dy[k];
					if (px > m || py > n || px < 1 || py < 1)
						continue;
					if (a[px][py] == 'W')
						continue;
					if ((d[px][py] > d[x][y] + 1) || !d[px][py]) {
						d[px][py] = d[x][y] + 1;
						s = max(s, d[px][py]);
						p.push({ px, py });
					}
				}
			}
		}
	}
	printf("%d", s);
	return 0;
}