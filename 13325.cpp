#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int a[2097160];
int n, m;

long long s;

long long sol(int i) {
	long long l, r, x;
	if (2 * i <= m + 1) {
		l = sol(2 * i);
		r = sol(2 * i + 1);
	}
	else		return 0;
	if (l + a[2 * i] > r + a[2 * i + 1]) {
		a[2 * i + 1] = l + a[2 * i] - r;
		x = a[2 * i + 1] + r;
	}
	else {
		a[2 * i] = r + a[2 * i + 1] - l;
		x = a[2 * i] + l;
	}
	s += a[2 * i] + a[2 * i + 1];
	return x;
}

int main() {
	scanf("%d", &n);
	m = pow(2, n + 1) - 2;
	for (int i = 1; i <= m; scanf("%d", &a[i++ + 1]));

	sol(1);

	printf("%lld", s);

	return 0;
}