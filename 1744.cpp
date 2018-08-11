#include <iostream>
#include <algorithm>
using namespace std;

int n, m, z, a[10001];
long long s;

bool comp(int x, int y) {
	return x > y;
}

long long sumP(int x) {
	long long t = 0;
	int c;
	if (x % 2)
		c = (x - 1) / 2;
	else
		c = x / 2;

	for (int i = 0, j = 1; j <= c; i += 2, j++)
		t += max(a[i] * a[i + 1], a[i] + a[i + 1]);
	if (x % 2)
		t += a[x - 1];
	return t;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (!a[i])
			z++;
		else if (a[i] < 0)
			m++;
	}

	sort(a, a + n, comp);
	if (!z && !m)
		s = sumP(n);
	else if (!m && z) {
		s = sumP(n - z);
	}
	else if (m && !z) {
		s = sumP(n - m);
		reverse(a, a + n);
		s += sumP(m);
	}
	else {
		s = sumP(n - m - z);
		reverse(a, a + n);
		if (m % 2)
			s += sumP(m - 1);
		else
			s += sumP(m);
	}
	printf("%lld", s);
	return 0;
}