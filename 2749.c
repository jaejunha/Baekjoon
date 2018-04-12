#include <stdio.h>

long long n;
int m;
int a[1500001];

int main() {


	scanf("%lld", &n);
	m = n % 1500000;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= m; i++)
		a[i] = (a[i - 1] + a[i - 2]) % 1000000;

	printf("%d", a[m]);

	return 0;
}