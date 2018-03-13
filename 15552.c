#include <stdio.h>

int main() {
	int int_a, int_b;
	int int_count;

	scanf("%d", &int_count);
	for (int i = 0; i < int_count; i++) {
		scanf("%d %d", &int_a, &int_b);
		printf("%d\n", int_a + int_b);
	}

	return 0;
}