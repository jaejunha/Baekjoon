/* reference: https://fatc.club/2017/03/01/1419 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, w, s[1025][1025];

void update(int x, int y, int val) {
	for (int i = x; i <= n; i += (i&-i)) {
		for (int j = y; j <= n; j += (j&-j))
			s[i][j] += val;
	}
}
int sum(int x, int y) {
	int ret = 0;
	for (int i = x; i > 0; i &= (i - 1))
		for (int j = y; j > 0; j &= (j - 1))
			ret += s[i][j];
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, val; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &val);
			update(i, j, val);
		}
	while (m--) {
		scanf("%d", &w);
		if (!w) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			update(x, y, c - sum(x, y) + sum(x - 1, y) + sum(x, y - 1) - sum(x - 1, y - 1));
		}
		else {
			int x[2], y[2];
			scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
			printf("%d\n", sum(x[1], y[1]) - sum(x[0] - 1, y[1]) - sum(x[1], y[0] - 1) + sum(x[0] - 1, y[0] - 1));
		}
	}
	return 0;
}
