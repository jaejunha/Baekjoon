/* Because of time error, this code didn't work well */
#include <stdio.h>
#include <stdlib.h>

int array_sort[1000000];

void merge(int start, int mid, int end) {
	int *array_temp;
	int int_i = start, int_j = mid + 1;
	int int_index = 0;
	array_temp = (int*)malloc(sizeof(int)*(end - start + 1));

	for (int i = 0, length = end - start + 1; i < length; i++) {
		if (int_i > mid)
			array_temp[i] = array_sort[int_j++];
		else if (int_j > end)
			array_temp[i] = array_sort[int_i++];
		else if (array_sort[int_i] < array_sort[int_j])
			array_temp[i] = array_sort[int_i++];
		else
			array_temp[i] = array_sort[int_j++];
	}
	for (int i = start, j = 0; i <= end; array_sort[i++] = array_temp[j++]);

	free(array_temp);
}

void mergeSort(int start, int end) {
	if (start < end) {
		int int_mid = (start + end) / 2;
		mergeSort(0, int_mid);
		mergeSort(int_mid + 1, end);
		merge(start, int_mid, end);
	}
}

int main() {

	int int_n;

	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%d", &array_sort[i]);
	}
	mergeSort(0, int_n-1);
	for (int i = 0; i < int_n; printf("%d\n", array_sort[i]), i++);
	return 0;
}