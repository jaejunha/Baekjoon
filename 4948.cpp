#include <stdio.h>
#include <math.h>

#define MAX 123456*2

bool bool_che[MAX + 1];

int main() {


	bool_che[1] = true;
	for (int i = 2; i < sqrt(MAX); i++) {
		for (int j = 2; i*j <= MAX; j++)
			bool_che[i*j] = true;
	}

	int int_n;
	int int_count;
	while (1) {
		scanf("%d", &int_n);
		if (int_n != 0) {
			int_count = 0;
			for (int i = int_n + 1; i <= 2 * int_n; i++) {
				(!bool_che[i]) ? int_count++ : i;
			}
		}
		else
			break;
		printf("%d\n", int_count);
	}
	return 0;
}