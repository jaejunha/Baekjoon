/* reference: https://fatc.club/2017/03/01/1109 */
#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#define INF 100000

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int T;
int n, m, k;
int sol;
int d[101][10001];
vector<PP> v[101];
priority_queue<PP, vector<PP>, greater<PP>> p;

int main() {

	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int x, y, z, w; k--;) {
			scanf("%d%d%d%d", &x, &y, &z, &w);
			v[x].push_back({ w,{ y,z } });
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++)
				d[i][j] = INF;
		}
		d[1][0] = 0;
		p.push({ 0,{ 1,0 } });

		int e, c, t;
		while (!p.empty()) {
			e = p.top().second.first;
			c = p.top().second.second;
			t = p.top().first;
			p.pop();

			for (auto it : v[e]) {
				if (c + it.second.second > m)
					continue;
				if (d[it.second.first][c + it.second.second] > d[e][c] + it.first) {
					d[it.second.first][c + it.second.second] = d[e][c] + it.first;
					p.push({ d[it.second.first][c + it.second.second],{ it.second.first , c + it.second.second } });
				}
			}
		}
		sol = INF;
		for (int i = 0; i <= m; i++)
			sol = min(sol, d[n][i]);

		if (sol == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", sol);
		for (int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}