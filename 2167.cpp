/* reference: http://jaimemin.tistory.com/411 */
#include <iostream>
using namespace std;

int n, m, t, a[301][301];
long long b[301][301];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
	scanf("%d", &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
	}
	int x[2], y[2];
	while (t--) {
		scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
		printf("%lld\n", b[x[1]][y[1]] - b[x[0] - 1][y[1]] - b[x[1]][y[0] - 1] + b[x[0] - 1][y[0] - 1]);
	}
	return 0;
}