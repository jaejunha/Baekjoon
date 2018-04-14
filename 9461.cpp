#include <stdio.h>
using namespace std;

int n, k;
long long a[101];
int main() {

	a[1] = a[2] = a[3] = 1;

	for (int i = 4; i <= 100; i++)
		a[i] = a[i - 2] + a[i - 3];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		printf("%lld\n", a[k]);
	}

	return 0;
}