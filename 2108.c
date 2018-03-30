#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int array_sort[500000];
int array_count[8001];
int int_flag;
int int_max;

int main() {

	int int_n;
	double double_sum = 0;

	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%d", &array_sort[i]);
		double_sum += array_sort[i];
		array_count[array_sort[i] + 4000]++;
	}

	sort(array_sort, array_sort + int_n);
	printf("%d\n", (int)(floor(double_sum / int_n + 0.5)));
	printf("%d\n", array_sort[(int_n - 1) / 2]);
	for (int i = 0; i < 8001; i++) {
		if (array_count[i] > int_max)
			int_max = array_count[i];
	}
	int int_first = -4001;
	int int_second = -4001;
	for (int i = 0; i < int_n; i++) {
		if (array_count[array_sort[i] + 4000] == int_max) {
			if (int_first == -4001)
				int_first = array_sort[i];
			else if(array_sort[i]!=int_first && int_second == -4001)
				int_second = array_sort[i];
		}
	}
	if (int_second != -4001)
		printf("%d\n", int_second);
	else
		printf("%d\n", int_first);
	printf("%d\n", array_sort[int_n - 1] - array_sort[0]);

	return 0;
}