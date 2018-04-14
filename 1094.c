#include <stdio.h>

int n;
int s;

int main() {

	scanf("%d", &n);
	while (n != 1) {
		s += (n % 2);
		n /= 2;
	}

	printf("%d", s + 1);
	return 0;
}