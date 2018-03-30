#include <stdio.h>
#include <math.h>

int main() {

	int int_n, int_r, int_c;
	int int_sum = 0;
	scanf("%d %d %d", &int_n, &int_r, &int_c);
	for (int i = (int)pow(2, int_n - 1); i >= 2; i/=2) {
		if (int_r / i != 0) {
			int_sum += 2 * (int)pow(i, 2);
			int_r -= i;
		}
		if (int_c / i != 0) {
			int_sum += (int)pow(i, 2);
			int_c -= i;
		}
	}
	int_sum += 2 * int_r + int_c;
	printf("%d", int_sum);
	return 0;
}