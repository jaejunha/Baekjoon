#include <vector>
#include <stdio.h>
#define INF 5000000

using namespace std;

typedef pair<int, int> P;

int t, n, m, w, d[501];
bool c;
vector<P> v[501];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &w);
		for (int x, y, z; m--;) {
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({ y,z });
			v[y].push_back({ x,z });
		}
		for (int x, y, z; w--;) {
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({ y,-z });
		}
		fill(d, d + n + 1, INF);
		d[1] = 0;
		c = false;
		for (int i = 1, x, y; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto it : v[j]) {
					x = it.first;
					y = it.second;
					if (d[j] != INF && d[x] > d[j] + y) {
						d[x] = d[j] + y;
						if (i == n) {
							printf("YES\n");
							c = true;
							break;
						}
					}
				}
				if (c)
					break;
			}
		}
		if (!c)
			printf("NO\n");
		for (int i = 1; i <= n; v[i++].clear());
	}
	return 0;
}