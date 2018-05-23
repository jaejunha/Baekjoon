/* reference: http://hsp1116.tistory.com/43 */
/* reference: https://jaejin0me.github.io/post/algo42/ */
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m;
int s;
vector<pair<int, int>> v[20001];
int d[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &s);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({ y,z });
	}

	for (int i = 1; i <= n; i++) {
		if (i == s)
			d[i] = 0;
		else
			d[i] = 300000;
	}
	p.push({ d[s],s });

	int x, y;
	while (!p.empty()) {
		x = p.top().first;
		y = p.top().second;
		p.pop();

		if (x > d[y])
			continue;
		for (auto it : v[y]) {
			if (d[it.first] > d[y] + it.second) {
				d[it.first] = d[y] + it.second;
				p.push(make_pair(d[it.first], it.first));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 300000)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
	return 0;
}