#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	long long n, k;

	scanf("%lld", &n);
	scanf("%lld", &k);

	long long x, s, l, r;
	l = 1;
	r = n * n;
	while (l <= r) {
		x = (l + r) / 2;
		s = 0;
		for (long long i = 1; i <= n; s += min(x / i++, n));

		if (k <= s)
			r = x - 1;
		else
			l = x + 1;
	}
	printf("%lld", l);
	return 0;
}