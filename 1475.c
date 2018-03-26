#include <stdio.h>
#include <math.h>

int int_check[10];

int main() {
	int int_n;
	int int_max = 0;
	scanf("%d", &int_n);

	if (int_n == 0) {
		printf("1");
		return 0;
	}

	for (;; int_n /= 10) {
		if (int_n == 0) {
			//int_check[0]++;
			break;
		}

		int_check[int_n % 10]++;
	}

	int_check[6] += int_check[9];
	int_check[6] = ceil((double)int_check[6]/2);

	for (int i = 0; i < 9; i++) {
		if (int_max < int_check[i])
			int_max = int_check[i];
	}

	printf("%d", int_max);

	return 0;
}