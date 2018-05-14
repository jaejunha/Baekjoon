#include <stdio.h>

int n, m, s, t;
int a[1000001];

int main() {

	scanf("%d", &n);
	for (scanf("%d", &m); m--;) {
		scanf("%d %d", &s, &t);
		if (s < t) {
			a[s]++;
			a[t]--;
		}
	}
	t = n;
	s = 0;
	for (int i = 1; i < n; i++) {
		s += a[i];
		if (s != 0)
			t--;
	}
	printf("%d", t);
	return 0;
}