#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P>> p;
vector<P> v[1001];
vector<int> sol;
int n, m, e;
int d[1001];

bool comp(int a, int b) {
	return a > b;
}

void dijkstra(int start) {

	for (int i = 1; i <= n; i++) {
		if (i == start)
			d[i] = 0;
		else
			d[i] = 10000000;
	}
	p.push({ d[start],start });
	int x, y;
	while (!p.empty()) {
		x = p.top().first;
		y = p.top().second;
		p.pop();

		for (auto it : v[y]) {
			if (d[it.second] > x + it.first) {
				d[it.second] = x + it.first;
				p.push({ d[it.second],it.second });
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &e);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({ z, y });
	}

	for (int i = 1; i <= n; i++) {
		if (i == e)
			continue;
		dijkstra(i);
		sol.push_back(d[e]);
	}
	dijkstra(e);
	for (int i = 1, j = 0; i <= n; i++) {
		if (i == e)
			continue;
		sol.at(j++) += d[i];
	}

	sort(sol.begin(), sol.end(), comp);
	printf("%d", sol.at(0));
	return 0;
}