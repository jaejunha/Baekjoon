#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int n, m;
int a, b;
long long c[30][30];

long long cal(int x, int y) {
	if (y == x || y == 0)
		return 1;
	if (y == 1 || y == x - 1)
		return x;

	long long &ret = c[x][y];
	if (ret)
		return ret;

	ret = cal(x - 1, y - 1) + cal(x - 1, y);

	return ret;
}

int main() {
	for (int i = 1; i < 30; i++) {
		c[i][0] = c[i][i] = 1;
		c[i][1] = c[i][i - 1] = i;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a = max(n, m);
		b = min(n, m);
		if (c[a][b])
			printf("%lld\n", c[a][b]);
		else if (c[a][a - b])
			printf("%lld\n", c[a][a - b]);
		else {
			printf("%lld\n", cal(a, min(b, a - b)));
		}
	}
	return 0;
}