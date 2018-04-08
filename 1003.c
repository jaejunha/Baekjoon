#include <stdio.h>

int n;
int a[41];
int b[41];
int main() {

	int c;
	a[0] = 1;
	b[1] = 1;
	for (int i = 2; i <= 41; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		printf("%d %d\n", a[c], b[c]);
	}

	return 0;
}