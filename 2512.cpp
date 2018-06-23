#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[10001];
long long L, l, r, m;
long long s, answer;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; scanf("%d", &a[i++]));
	sort(a, a + n);
	scanf("%lld", &L);
	l = 0;
	r = L;
	while (l <= r) {
		m = (l + r) / 2;
		s = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > m)
				s += m;
			else
				s += a[i];
		}
		if (s > L)
			r = m - 1;
		else {
			l = m + 1;
			answer = max(answer, m);
		}
	}
	if (a[n - 1] < answer)
		answer = a[n - 1];
	printf("%lld", answer);

	return 0;
}