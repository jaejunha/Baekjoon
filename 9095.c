#include <stdio.h>

int n;
int a[11];

int main() {
	a[0] = 1;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i - j >= 0)
				a[i] += a[i - j];
		}
	}
	scanf("%d", &n);
	for (int i = 1, t; i <= n; i++) {
		scanf("%d", &t);
		printf("%d\n", a[t]);
	}
	return 0;
}