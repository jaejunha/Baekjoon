/* Because of runtime error, this code didn't work well */
#include <stdio.h>
#include <stdlib.h>
int array_origin[10000001];
int array_sort[10000001];

int main() {

	int int_n;
	int int_max = 0;
	int *array_count;

	scanf("%d", &int_n);
	for (int i = 1; i <= int_n; i++) {
		scanf("%d", &array_origin[i]);
		if (int_max < array_origin[i])
			int_max = array_origin[i];
	}
	array_count = (int*)malloc(sizeof(int)*(int_max + 1));
	for (int i = 1; i <= int_max; array_count[i++] = 0);
	for (int i = 1; i <= int_n; array_count[array_origin[i++]]++);
	for (int i = 1, sum = 0; i <= int_max; i++) {
		if (array_count[i] != 0) {
			sum += array_count[i];
			array_count[i] = sum;
		}
	}
	for (int i = int_n; i >= 1; i--) {
		array_sort[array_count[array_origin[i]]] = array_origin[i];
		array_count[array_origin[i]]--;
	}
	for (int i = 1; i <= int_n; i++) {
		printf("%d\n", array_sort[i]);
	}
	free(array_count);
	return 0;
}