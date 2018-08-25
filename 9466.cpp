/* reference: http://lmcoa15.tistory.com/51 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, g;
vector<int> v, p;
int c[100001];
bool b[100001];

int dfs(int x, int d) {
	if (c[x]) {
		if (b[x])
			return 0;

		return (d - c[x]);
	}
	c[x] = d;
	p.push_back(x);
	return dfs(v[x], d + 1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.resize(n + 1);
		g = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			c[i] = 0;
			b[i] = false;
		}

		for (int i = 1; i <= n; i++) {
			if (!b[i]) {
				g += dfs(i, 1);
				for (int j : p)
					b[j] = true;
				p.clear();
			}
		}
		printf("%d\n", n - g);
	}
	return 0;
}