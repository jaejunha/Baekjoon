#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
int n, m;
int a[9][9];
int c, l;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ans;
/************************
	v: empty space	
	z: virus		
*************************/
vector<P> v, z;

void bfs(vector<P> u) {
	int b[9][9];
	int e = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			b[i][j] = a[i][j];
	}

	for (P p : u)
		b[p.first][p.second] = 1;

	queue<P> q;
	for (P p : z)
		q.push(p);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		b[x][y] = 2;
		for (int k = 0; k < 4; k++) {
			int px = x + dx[k];
			int py = y + dy[k];
			if (px > n || py > m || px < 1 || py < 1)
				continue;
			if (!b[px][py])
				q.push({ px, py });
		}
	}
	e = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!b[i][j])
				e++;
		}
	}
	ans = max(ans, e);
}

void dfs(int x, vector<P> u) {
	if (c == 3)
		bfs(u);
	else {
		for (int i = x + 1; i < l; i++) {
			vector<P> w = u;
			w.push_back(v.at(i));
			c++;
			dfs(i, w);
			c--;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
			if (!a[i][j])
				v.push_back({ i,j });
			else if (a[i][j] == 2)
				z.push_back({ i,j });
		}
	}

	l = v.size();
	for (int i = 0; i < l; i++) {
		vector<P> u;
		u.push_back(v.at(i));
		c = 1;
		dfs(i, u);
	}

	printf("%d", ans);
	return 0;
}