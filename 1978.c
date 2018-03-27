#include <stdio.h>
#include <math.h>

int main() {

	int int_count;
	int int_n;
	int int_answer=0;

	scanf("%d", &int_count);
	for (int i = 0; i < int_count; i++) {
		scanf("%d", &int_n);

		if (int_n == 2) 
			int_answer++;
		
		for (int j = 2; j < int_n; j++) {
			if (j == int_n - 1) {
				int_answer++;
			}
			if (int_n % j == 0)
				break;
		}
	}
	printf("%d", int_answer);
	return 0;
}