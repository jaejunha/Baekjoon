#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct Z {
	int x, y;
	char c;
}Z;
char a[6][6];
Z z[7];
int t;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int c, int m) {
	if (c == 7) {
		int s = 0;
		bool b[6][6];
		for (int i = 1; i <= 5; i++)
			for (int j = 1; j <= 5; j++)
				b[i][j] = false;
		for (int i = 0; i < 7; i++) {
			b[z[i].x][z[i].y] = true;
			if (z[i].c == 'S')
				s++;
		}
		if (s >= 4) {
			bool v[6][6];
			for (int i = 1; i <= 5; i++)
				for (int j = 1; j <= 5; j++)
					v[i][j] = false;
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 5; j++) {
					if (b[i][j]) {
						queue<pair<int, int>> q;
						q.push({ i,j });
						s = 0;
						while (q.size()) {
							int x = q.front().first;
							int y = q.front().second;
							q.pop();
							if (!v[x][y]) {
								v[x][y] = true;
								s++;
							}

							for (int k = 0, px, py; k < 4; k++) {
								px = x + dx[k];
								py = y + dy[k];
								if (px > 5 || py > 5 || px < 1 || py < 1)
									continue;
								if (b[px][py] && !v[px][py])
									q.push({ px, py });
							}
						}
						if (s == 7)
							t++;
						return;
					}
				}
			}
		}
	}
	else {
		for (int i = m; i <= 25; i++) {
			int x = (i - 1) / 5 + 1;
			int y = (i - 1) % 5 + 1;
			z[c].x = x;
			z[c].y = y;
			z[c].c = a[x][y];
			dfs(c + 1, i + 1);
		}
	}
}

int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			scanf("%c", &a[i][j]);
		scanf("%c", &t);
	}

	t = 0;

	for (int i = 1; i <= 25; i++) {
		int x = (i - 1) / 5 + 1;
		int y = (i - 1) % 5 + 1;
		z[0].x = x;
		z[0].y = y;
		z[0].c = a[x][y];
		dfs(1, i + 1);
	}
	printf("%d", t);
	return 0;
}