#include <cstdio>

int n, a[1001];

int main() {
	scanf("%d", &n);
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= n; i++)
		a[i] = (a[i - 1] + 2 * a[i - 2]) % 10007;
	printf("%d", a[n]);
	return 0;
}