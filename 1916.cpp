#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m, s, e;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
int d[1001];

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({ z,y });
	}
	scanf("%d%d", &s, &e);

	for (int i = 1; i <= n; i++) {
		if (i == s)
			d[i] = 0;
		else
			d[i] = 100000001;
	}

	p.push({ d[s],s });
	int x, y;
	while (!p.empty()) {
		x = p.top().first;
		y = p.top().second;
		p.pop();

		if (d[y] < x)
			continue;
		for (auto it : v[y]) {
			if (d[it.second] > d[y] + it.first) {
				d[it.second] = d[y] + it.first;
				p.push({ d[it.second], it.second });
			}
		}
	}
	printf("%d", d[e]);
	return 0;
}