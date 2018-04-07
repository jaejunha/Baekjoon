#include <stdio.h>
#include <algorithm>

using namespace std;

int int_m, int_n;
int array_m[500000], array_n[500000];

int binarySearch(int n) {

	int left = 0;
	int right = int_m - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (array_m[mid] == n)
			return 1;
		else if (array_m[mid] > n)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main() {

	scanf("%d", &int_m);
	for (int i = 0; i < int_m; scanf("%d", array_m + i++));

	scanf("%d", &int_n);
	for (int i = 0; i < int_n; scanf("%d", array_n + i++));

	sort(array_m, array_m + int_m);

	for (int i = 0; i < int_n; i++) {
		printf("%d ", binarySearch(array_n[i]));
	}

	return 0;
}