#include <iostream>

using namespace std;
int t, n, m;
int a, b, s;
int p[1001];
bool g[1001][1001];

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	if (i != j)
		p[i] = j;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		s = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				g[i][j] = false;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			g[a][b] = g[b][a] = true;
		}
		for (int i = 1; i <= n; i++)
			p[i] = i;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][j]) {
					if (find(i) != find(j)) {
						s++;
						merge(i, j);
					}
				}
			}
		}
		printf("%d\n", s);
	}
	return 0;
}