#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long m;

vector<pair<int, int>> v[10001];

long long dfs(int x) {
	long long l = 0, r = 0, t;
	long long p_m = 0;
	for (auto it = v[x].begin(); it != v[x].end(); it++) {
		if (l == 0)
			l = dfs((*it).first) + (*it).second;
		else if (r == 0) {
			r = dfs((*it).first) + (*it).second;
			if (l > r)
				swap(l, r);
		}
		else {
			t = dfs((*it).first) + (*it).second;
			if (t > r) {
				l = r;
				r = t;
			}
			else if (t > l)
				l = t;
		}
	}
	m = max(m, l + r);
	return max(l, r);
}

int main() {

	scanf("%d", &n);

	for (int i = 1, x, y, z; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back({ y,z });
	}

	dfs(1);
	printf("%lld", m);

	return 0;
}