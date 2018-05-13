#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t;
int n, m;
int in[501];
int g[501][501];
queue<int> q;
int r[501];
vector<int> v;

void init() {
	while (!q.empty())
		q.pop();
	memset(in, 0, sizeof(in));
	memset(r, 0, sizeof(r));
	memset(g, 0, sizeof(g));
	v.clear();
}

int main() {
	scanf("%d", &t);

	for (int i = 0, x, y; i < t; i++) {
		scanf("%d", &n);
		init();
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			r[x] = j;
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (r[j] < r[k]) {
					g[j][k]++;
					in[k]++;
				}
			}
		}

		scanf("%d", &m);
		for (int j = 1; j <= m; j++) {
			scanf("%d %d", &x, &y);
			if (g[x][y]) {
				g[x][y]--;
				g[y][x]++;
				in[y]--;
				in[x]++;
			}
			else {
				g[x][y]++;
				g[y][x]--;
				in[y]++;
				in[x]--;
			}
		}

		for (int j = 1; j <= n; j++) {
			if (in[j] == 0)
				q.push(j);
		}

		y = 0;
		while (!q.empty()) {
			if (q.size() > 1) {
				y = 1;
				break;
			}
			x = q.front();
			q.pop();
			v.push_back(x);
			for (int j = 1; j <= n; j++) {
				if (x == j)
					continue;
				if (g[x][j]) {
					in[j]--;
					if (in[j] == 0)
						q.push(j);
				}
			}
		}
		if (y == 1)
			printf("?\n");
		else {
			if (v.size() == n) {
				for (int i = 0; i < n; i++)
					printf("%d ", v.at(i));
				printf("\n");
			}
			else
				printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}