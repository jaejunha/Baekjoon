#include <stdio.h>

int n, m;
int g[1001][1001];
int v[1001];
int answer;

void check(int i) {
	v[i] = 1;
	for (int j = 1; j <= n; j++) {
		if (!v[j] && g[i][j]) {
			g[i][j] = g[j][i] = 0;
			check(j);
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d %d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			answer++;
			check(i);
		}
	}

	printf("%d", answer);

	return 0;
}