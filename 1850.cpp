#include <stdio.h>
#include <algorithm>

using namespace std;

long long gcd(long long c, long long d) {
	long long x = max(c, d);
	long long y = min(c, d);
	long long r = x % y;

	while (r) {
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

long long a, b, g;

int main() {
	scanf("%lld %lld", &a, &b);

	g = gcd(a, b);
	for (long long i = 0; i < g; i++) {
		printf("1");
	}
	return 0;
}