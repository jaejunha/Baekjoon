#include <stdio.h>
#include <math.h>

long long n;
long long total = 1;

int main() {
	scanf("%lld", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	long long r = n;
	for (long long i = 2, k = sqrt(n), s; r > 1 && i <= k; i++) {
		if (r%i == 0) {
			s = i - 1;
			r /= i;
			while (r%i == 0) {
				r /= i;
				s *= i;
			}
			total *= s;
		}
	}
	if (r == n) {
		printf("%lld", n - 1);
		return 0;
	}

	if (r != 1) {
		total *= (r - 1);
	}
	printf("%lld", total);

	return 0;
}