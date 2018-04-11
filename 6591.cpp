#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;

int main() {
	int a, b;
	long long sum;
	while (1) {
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0)
			break;
		sum = 1;
		a = n;
		b = min(k, n - k);

		for (int i = 0; i < b; i++) {
			sum *= (a - i);
			sum /= (i + 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}