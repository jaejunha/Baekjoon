#include <stdio.h>

long long arr_answer[91];

int main() {

	int int_n;

	scanf("%d", &int_n);
	arr_answer[1] = 1;
	for (int i = 2; i <= int_n; i++)
		arr_answer[i] = arr_answer[i - 1] + arr_answer[i - 2];
	printf("%lld", arr_answer[int_n]);
	return 0;
}