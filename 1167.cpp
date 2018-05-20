#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long m;
int root;

vector<pair<int, int>> v[100001];
bool b[100001];

long long dfs(int x) {
	b[x] = true;
	long long l = 0, r = 0, t;
	long long p_m = 0;
	for (auto it = v[x].begin(); it != v[x].end(); it++) {
		if (b[(*it).first])
			continue;
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

	for (int i = 0, x, y, z; i < n; i++) {
		scanf("%d", &x);
		while (1) {
			scanf("%d", &y);
			if (y == -1)
				break;
			scanf("%d", &z);
			v[x].push_back({ y,z });
			if (root == 0 || y == root)
				root = x;
		}
	}

	dfs(root);
	printf("%lld", m);

	return 0;
}