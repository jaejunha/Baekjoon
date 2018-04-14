#include <stdio.h>

int main() {

	int n, c = 0;
	int a, b;
	scanf("%d %d %d", &n, &a, &b);
	if (a > n || b > n) {
		printf("-1");
		return 0;
	}
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		c++;
		n /= 2;
	}

	printf("%d", c);

	return 0;
}