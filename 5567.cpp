#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, s;
int g[501][501];
bool b[501];
vector<int> v;
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		g[x][y] = g[y][x] = 1;
		if (x == 1 || y == 1) {
			if (!b[x] || !b[y]) {
				v.push_back(y);
				b[x] = true;
				b[y] = true;
			}
		}
	}
	s = v.size();
	for (int i = 0, l = s; i < l; i++) {
		for (int j = 2; j <= n; j++) {
			if (v[i] == j)
				continue;
			if (!g[v[i]][j])
				continue;
			if (!b[j] || !b[v[i]]) {
				s++;
				b[j] = true;
				b[v[i]] = true;
			}
		}
	}
	printf("%d", s);
	return 0;
}