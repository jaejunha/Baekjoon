#include <stdio.h>
#include <math.h>

#define MAX 10000

bool bool_che[MAX + 1];

int main() {


	bool_che[1] = true;
	for (int i = 2; i < sqrt(MAX); i++) {
		for (int j = 2; i*j <= MAX; j++)
			bool_che[i*j] = true;
	}

	int int_n;
	int int_a;
	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%d", &int_a);
		if (int_a == 4)
			printf("2 2\n");
		else {
			for (int i = int_a / 2; i > 1; i--) {
				if (!bool_che[i] && !bool_che[int_a - i]) {
					printf("%d %d\n", i, int_a - i);
					break;
				}
			}
		}
	}
	return 0;
}