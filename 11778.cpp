#include <stdio.h>
#include <algorithm>

using namespace std;

long long m, n, gcd;
long long a[2][2], p[2][2], t[2][2];
long long getGCD(long long m, long long n) {
	long long a = max(m, n);
	long long b = min(m, n);
	long long r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	scanf("%lld %lld", &m, &n);

	gcd = getGCD(m, n);

	if (n <= 2)
		printf("1");
	else {
		p[0][0] = 1;
		p[0][1] = 1;
		p[1][0] = 1;
		p[1][1] = 0;

		for (long long i = gcd, s = 1; i; i >>= 1, s <<= 1) {
			if (i % 2 == 1) {
				if (a[0][0] == 0) {
					a[0][0] = p[0][0];
					a[0][1] = p[0][1];
					a[1][0] = p[1][0];
					a[1][1] = p[1][1];
				}
				else {
					t[0][0] = (a[0][0] * p[0][0]) % 1000000007 + (a[0][1] * p[1][0]) % 1000000007;
					t[0][1] = (a[0][0] * p[0][1]) % 1000000007 + (a[0][1] * p[1][1]) % 1000000007;
					t[1][0] = a[1][0] * p[0][0] + a[1][1] * p[1][0];
					t[1][1] = a[1][0] * p[0][1] + a[1][1] * p[1][1];
					a[0][0] = t[0][0];
					a[0][1] = t[0][1];
					a[1][0] = t[1][0];
					a[1][1] = t[1][1];

					t[0][0] = a[0][0] * 1 + a[0][1] * 1;
					t[0][1] = a[0][0] * 1 + a[0][1] * 0;
					t[1][0] = a[1][0] * 1 + a[1][1] * 1;
					t[1][1] = a[1][0] * 1 + a[1][1] * 0;
					a[0][0] = t[0][0];
					a[0][1] = t[0][1];
					a[1][0] = t[1][0];
					a[1][1] = t[1][1];
				}
			}

			if (s != 1) {
				t[0][0] = p[0][0] * p[0][0] + p[0][1] * p[1][0];
				t[0][1] = p[0][0] * p[0][1] + p[0][1] * p[1][1];
				t[1][0] = p[1][0] * p[0][0] + p[1][1] * p[1][0];
				t[1][1] = p[1][0] * p[0][1] + p[1][1] * p[1][1];
				p[0][0] = t[0][0];
				p[0][1] = t[0][1];
				p[1][0] = t[1][0];
				p[1][1] = t[1][1];

				t[0][0] = p[0][0] * 1 + p[0][1] * 1;
				t[0][1] = p[0][0] * 1 + p[0][1] * 0;
				t[1][0] = p[1][0] * 1 + p[1][1] * 1;
				t[1][1] = p[1][0] * 1 + p[1][1] * 0;
				p[0][0] = t[0][0];
				p[0][1] = t[0][1];
				p[1][0] = t[1][0];
				p[1][1] = t[1][1];
			}
		}
		if (gcd % 2)
			printf("%lld ", a[0][1]);
		else
			printf("%lld ", a[0][0]);
	}
	return 0;
}