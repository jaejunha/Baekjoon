#include <stdio.h>

int n;
int c;
int main() {
	scanf("%d", &n);

	for (int i = n; i > 0; i /= 10, c++);
	for (int i = n - 9 * c, s; i < n; i++) {
		s = i;
		for (int j = i; j > 0; s += j % 10, j /= 10);
		if (s == n) {
			printf("%d", i);
			return 0;
		}

	}

	printf("0");

	return 0;
}