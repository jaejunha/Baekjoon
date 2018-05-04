#include <stdio.h>

int n, a;

int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &a);
		if (a < 4 || a == 6)
			printf("0\n");
		else if (a == 4)
			printf("2\n");
		else
			printf("1\n");
	}
	return 0;
}