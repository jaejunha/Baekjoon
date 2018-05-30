#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define INF 800000

using namespace std;

int n, m;
int a, b;
vector<pair<int, int >> v[801];
int d[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

void path(int s) {

	while (!p.empty())
		p.pop();

	for (int i = 1; i <= n; i++) {
		if (i == s)
			d[i] = 0;
		else
			d[i] = INF;
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
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	scanf("%d%d", &a, &b);

	int t[2][3];
	path(a);
	t[0][1] = t[1][1] = d[b];
	t[1][2] = d[n];
	path(1);
	t[0][0] = d[a];
	t[1][0] = d[b];
	path(b);
	t[0][2] = d[n];
	int s = min(t[0][0] + t[0][1] + t[0][2], t[1][0] + t[1][1] + t[1][2]);
	if (s >= INF)
		printf("-1");
	else
		printf("%d", s);
	return 0;
}