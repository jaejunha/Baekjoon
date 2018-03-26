#include <stdio.h>

int array_answer[15][15];

int getSum(int a, int b) {
	if (a == 0)
		return array_answer[a][b];
	if (b == 1)
		return 1;

	return getSum(a - 1, b) + getSum(a, b - 1);
}

int main() {
	int int_count;
	int int_a, int_b;

	for (int i = 1; i <= 14; array_answer[0][i]=i, i++);
	scanf("%d", &int_count);
	for (int i = 0; i < int_count; i++) {
		scanf("%d", &int_a);
		scanf("%d", &int_b);
		printf("%d\n", getSum(int_a, int_b));
	}

	return 0;
}