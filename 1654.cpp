#include <algorithm>
#include <stdio.h>

using namespace std;

long long n, a[10001], l = 1, r, m, t, s;
int k;

int main() {
	scanf("%d%lld", &k, &n);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &a[i]);
		r = max(r, a[i]);
	}

	while (l <= r) {
		m = (l + r) / 2;
		t = 0;
		for (int i = 1; i <= k; i++)
			t += (a[i] / m);
		if (t < n)
			r = m - 1;
		else {
			l = m + 1;
			s = max(s, m);
		}
	}
	printf("%lld", s);

	return 0;
}