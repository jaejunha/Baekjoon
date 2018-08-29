#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> P;
int n, t;
int x, y, a, b;
int r[101][101];
bool v[101];
queue<P> q;

int s = 101;
int main() {
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		r[a][b] = r[b][a] = 1;

	}
	if (x == y) {
		printf("0");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (i == x)
			continue;
		if (r[x][i]) {
			q.push({ i, 1 });
			v[x] = true;
		}
	}

	while (!q.empty()) {
		int now = q.front().first;
		int t = q.front().second;
		q.pop();
		if (v[now])
			continue;
		else
			v[now] = true;
		if (now == y)
			s = min(s, t);

		for (int i = 1; i <= n; i++) {
			if (i == now)
				continue;
			if (v[i])
				continue;
			if (r[now][i])
				q.push({ i,t + 1 });
		}
	}
	if (s == 101)
		printf("-1");
	else
		printf("%d", s);
	return 0;
}