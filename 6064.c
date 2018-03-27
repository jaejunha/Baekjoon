#include <stdio.h>

int main() {

	int int_count;
	int int_m, int_n, int_a, int_b;
	int int_flag = 0;

	scanf("%d", &int_count);
	for (int i = 0, int_sum; i < int_count; i++) {
		scanf("%d %d %d %d", &int_m, &int_n, &int_a, &int_b);
		if (int_m < 0 || int_n < 0 || int_m>40000 || int_n>40000 || int_a<0 || int_a>int_m || int_b<0 || int_b>int_n)
			printf("-1\n");
		else {
			int_flag = 0;
			for (int j = 0, k = 0; j < int_n && k < int_m;) {
				if (j*int_m + int_a == k*int_n + int_b) {
					printf("%d\n", j*int_m + int_a);
					int_flag = 1;
					break;
				}
				else if (j*int_m + int_a > k*int_n + int_b)
					k++;
				else
					j++;
			}
			if (int_flag == 0)
				printf("-1\n");
		}
	}
	return 0;
}