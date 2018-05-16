#include <stdio.h>

int n, m;
long long a[100001];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1, t; i <= n; i++) {
		scanf("%d", &t);
		a[i] = t + a[i - 1];
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d %d", &x, &y);
		printf("%lld\n", a[y] - a[x - 1]);
	}
	return 0;
}