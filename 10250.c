#include <stdio.h>

int main() {
	int int_h, int_w, int_n;
	int int_count;

	scanf("%d", &int_count);
	while(int_count--) {
		scanf("%d %d %d", &int_h, &int_w, &int_n);
		int_n--;
		printf("%d\n",((int)(int_n / int_h) + 1) + 100 * ((int_n % int_h)+1));
	}

	return 0;
}