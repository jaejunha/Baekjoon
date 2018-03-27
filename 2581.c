#include <stdio.h>
#include <math.h>

int main() {

	int int_m;
	int int_n;
	int int_answer=0;
	int int_min=0;

	scanf("%d", &int_m);
	scanf("%d", &int_n);
	for (int i = int_m; i <=int_n; i++) {
		
		if (i == 2 || i == 3) {
			int_answer += i;
			if (int_min == 0)
				int_min = i;
		}
		
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0)
				break;

			if ((j + 1)*(j + 1) > i) {
				int_answer+=i;
				if (int_min == 0)
					int_min = i;
				break;
			}
		}
	}
	if (int_answer == 0)
		printf("-1");
	else {
		printf("%d\n", int_answer);
		printf("%d\n", int_min);
	}
	return 0;
}