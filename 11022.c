#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);

	for (int i = 0, p, q; i < n; i++) {
		scanf("%d %d", &p, &q);
		printf("Case #%d: %d + %d = %d\n", i + 1, p, q, p + q);
	}

	return 0;
}