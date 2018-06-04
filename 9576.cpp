#include <cstdio>
#include <vector>

using namespace std;

int t, n, m;
int a, b;
int sol;
bool c[1001];
bool g[1001][1001];
int g_n[1001];
int g_m[1001];

bool dfs(int start) {
	if (c[start])
		return false;
	c[start] = true;

	for (int i = 1; i <= n; i++) {
		if (g[start][i]) {
			if (!g_n[i] || dfs(g_n[i])) {
				g_m[start] = i;
				g_n[i] = start;
				return true;
			}
		}
	}

	return false;
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			for (int j = a; j <= b; j++)
				g[i][j] = true;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; c[j++] = false);
			if (dfs(i))
				sol++;
		}
		printf("%d\n", sol);

		if (t) {
			sol = 0;
			for (int i = 1; i <= n; g_n[i++] = 0);
			for (int i = 1; i <= m; g_m[i++] = 0);
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++)
					g[i][j] = false;
			}
		}
	}
	return 0;
}