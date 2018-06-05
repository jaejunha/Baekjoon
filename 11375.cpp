#include <cstdio>

using namespace std;

int n, m;
bool g[1001][1001];
int g_n[1001], g_m[1001];
int sol;
bool b[1001];

bool dfs(int start) {
	if (b[start])
		return false;
	b[start] = true;

	for (int i = 1; i <= m; i++) {
		if (g[start][i]) {
			if (!g_m[i] || dfs(g_m[i])) {
				g_m[i] = start;
				g_n[start] = i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 1; j <= x; j++) {
			scanf("%d", &y);
			g[i][y] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			b[j] = false;

		if (dfs(i))
			sol++;
	}
	printf("%d", sol);

	return 0;
}