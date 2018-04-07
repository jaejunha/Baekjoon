#include <stdio.h>

long long n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	while (1) {
		if (n % 2 == 1) {
			printf("0");
			return 0;
		}
		n /= 2;
		if (n == 1) {
			printf("1");
			return 0;
		}
	}
	return 0;
}