#include <stdio.h>

int a[1001];
int b[1001];
int t, n, c;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		c = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j]);
			b[j] = 0;
		}
		for (int j = 1, k, l; j <= n; j++) {
			if (b[j])
				continue;
			k = j;
			while (1) {
				b[k] = 1;
				l = a[k];
				if (l == j) {
					c++;
					break;
				}
				k = l;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}