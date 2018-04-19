#include <stdio.h>

int n;
int l;
int a, c;

int main() {
	scanf("%d %d", &n, &l);

	for (int i = l, j; i <= 100; i++) {
		j = n - i * (i - 1) / 2;
		if (j % i == 0) {
			c = i;
			j /= i;
			if (j >= 0)
				a = j;
			else {
				printf("-1");
				return 0;
			}
			break;
		}
	}

	for (int i = 0; i<c; i++)
		printf("%d ", a + i);
	if (c == 0)
		printf("-1");
	return 0;
}