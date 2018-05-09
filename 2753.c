#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);
	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
		printf("1");
	else
		printf("0");
	return 0;
}