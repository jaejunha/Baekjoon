#include <stdio.h>

long long pow(long long t) {
	long long result = 1;
	long long a = t;
	long long y = 1000000005;
	while (y > 0) {
		if (y % 2) {
			result *= a;
			result %= 1000000007;
		}
		a *= a;
		a %= 1000000007;
		y /= 2;
	}
	return result;
}

int n;
int k;
long long s = 1;
long long t;

int main() {
	scanf("%d %d", &n, &k);

	for (int i = n; i > 0; i--)
		s = (s * i) % 1000000007;

	t = 1;
	for (int i = k; i > 0; i--)
		t = (t * i) % 1000000007;
	s = s * pow(t) % 1000000007;

	t = 1;
	for (int i = n - k; i > 0; i--)
		t = (t * i) % 1000000007;
	s = s * pow(t) % 1000000007;

	printf("%lld", s);
	return 0;
}