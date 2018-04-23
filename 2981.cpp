#include <stdio.h>
#include <math.h>
#include <set>
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

long long n;
long long g;

long long a[100];
long long b[99];

set<long long> s;

int main() {
	scanf("%d", &n);
	for (long long i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	for (long long i = 0; i < n - 1; i++)
		b[i] = abs(a[i + 1] - a[i]);

	g = b[0];
	for (long long i = 1; i < n - 1; i++)
		g = gcd(g, b[i]);

	s.insert(g);
	for (long long i = 2, m = sqrt(g); i <= m; i++) {
		if (g % i == 0) {
			s.insert(i);
			s.insert(g / i);
		}
	}

	for (set<long long>::iterator i = s.begin(); i != s.end(); i++)
		printf("%lld ", *i);

	return 0;
}