/* reference: http://jason9319.tistory.com/242 */
#include <iostream>
#include <algorithm>
using namespace std;

int r, c, sol;
char t;
int dx[] = { -1,0,1 };
int dy[] = { 1,1,1 };
int a[10000][500];
bool f[10000];

void dfs(int s, int x, int y) {
	if (y == c - 1) {
		if (!f[s]) {
			sol++;
			f[s] = true;
		}
	}
	else {
		if (f[s])
			return;
		for (int i = 0; i < 3; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (px >= r || py >= c || px < 0 || py < 0)
				continue;
			if (a[px][py])
				continue;
			a[px][py] = 2;
			dfs(s, px, py);
			if (f[s])
				return;
		}
	}
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%c", &t);
		for (int j = 0; j < c; j++) {
			scanf("%c", &t);
			if (t == 'x')
				a[i][j] = 1;
		}
	}

	for (int i = 0; i < r; i++)
		dfs(i, i, 0);
	printf("%d", sol);
	return 0;
}