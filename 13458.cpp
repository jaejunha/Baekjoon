#include <iostream>
using namespace std;

long long n, a[1000001], b, c, s;

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	scanf("%lld%lld", &b, &c);
	for (int i = 1; i <= n; i++) {
		s++;
		if (a[i] <= b)
			continue;

		a[i] -= b;
		if (a[i] % c)
			s += ((a[i] / c) + 1);
		else
			s += (a[i] / c);
	}
	printf("%lld", s);
	return 0;
}