#include <stdio.h>

int main() {
	int n;
	int p = 1;

	scanf("%d", &n);
	for (int i = 0, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a == p) p = b;
		else if (b == p)p = a;
	}

	printf("%d", p);

	return 0;
}