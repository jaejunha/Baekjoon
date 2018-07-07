#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w[11][11];
bool b[11];
int m = 10000001;
typedef pair<int, int> P;


void dfs(int x, vector<P> u) {
	if (u.size() == n) {
		int s = 0;
		bool a[11];
		for (int i = 0; i < n; i++) {
			a[u[i].first] = true;
			s += w[u[i].first][u[i].second];
		}
		for (int i = 1; i <= n; i++)
			if (!a[i])
				return;
		m = min(m, s);
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (i == x)
				continue;
			if (b[i])
				continue;
			if (!w[x][i])
				continue;
			vector<P> v = u;
			v.push_back({ x,i });
			b[i] = true;
			dfs(i, v);
			b[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	}
	for (int i = 2; i <= n; i++) {
		if (!w[1][i])
			continue;
		vector<P> v;
		v.push_back({ 1,i });
		b[i] = true;
		dfs(i, v);
		b[i] = false;
	}

	printf("%d", m);
	return 0;
}