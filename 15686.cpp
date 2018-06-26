#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int a[51][51];
vector<pair<int, pair<int, int> >> u;
vector<pair<int, int> > v;
int l_u, l_v;
int c;
int s, answer = 123456;

void dfs(int x, vector<pair<int, int> > z) {
	if (c == m) {

		for (int i = 0; i < l_u; i++)
			u[i].first = 123456;
		for (int i = 0; i < l_u; i++) {
			for (int j = 0; j < m; j++)
				u[i].first = min(u[i].first, abs(u[i].second.first - z[j].first) + abs(u[i].second.second - z[j].second));
		}

		s = 0;
		for (int i = 0; i < l_u; i++)
			s += u[i].first;
		answer = min(answer, s);
	}
	else {
		for (int i = x + 1; i < l_v; i++) {
			c++;
			vector<pair<int, int>> w = z;
			w.push_back(v[i]);
			dfs(i, w);
		}
	}
	c--;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
				u.push_back({ 1000,{ i,j } });
			else if (a[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	l_u = u.size();
	l_v = v.size();

	for (int i = 0; i < l_v; i++) {
		c = 1;
		vector<pair<int, int>> w;
		w.push_back(v[i]);
		dfs(i, w);
	}
	printf("%d", answer);
	return 0;
}