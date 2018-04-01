#include <stdio.h>
#include <algorithm>

using namespace std;

int int_array[5000000];

int main() {
	int int_n, int_k;
	scanf("%d %d", &int_n, &int_k);
	for (int i = 0; i < int_n; i++)
		scanf("%d", &int_array[i]);
	sort(int_array, int_array + int_n);
	printf("%d", int_array[int_k - 1]);
	return 0;
}