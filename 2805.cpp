#include <algorithm>
#include <stdio.h>

using namespace std;

long long n, m, a[1000001], l, r, mid, t, s;

int main() {

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		r = max(r, a[i]);
	}

	while (l <= r) {
		mid = (l + r) / 2;
		t = 0;
		for (int i = 1; i <= n; i++)
			t += ((a[i] - mid) > 0 ? a[i] - mid : 0);
		if (t < m)
			r = mid - 1;
		else {
			l = mid + 1;
			s = max(s, mid);
		}
	}
	printf("%lld", s);

	return 0;
}