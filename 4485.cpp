#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> X;

priority_queue<X, vector<X>, greater<X>> p;
int n;
int a[126][126];
int d[126][126];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int c;

int solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			d[i][j] = 10000;
	}
	d[1][1] = a[1][1];
	p.push({ d[1][1],{ 1,1 } });

	int x, y, z;
	while (!p.empty()) {
		z = p.top().first;
		x = p.top().second.first;
		y = p.top().second.second;
		p.pop();

		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];

			if (px > n || px < 1 || py > n || py < 1)
				continue;
			if (d[px][py] > z + a[px][py]) {
				d[px][py] = z + a[px][py];
				p.push({ d[px][py],{ px,py } });
			}
		}
	}

	return d[n][n];
}

int main() {
	while (1) {
		c++;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		}
		printf("Problem %d: %d\n", c, solve());
	}
	return 0;
}