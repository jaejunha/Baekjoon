#include <stdio.h>
#include <math.h>

bool bool_che[1000001];

int main() {

	int int_m, int_n;
	scanf("%d %d", &int_m, &int_n);
	bool_che[1] = true;
	for (int i = 2; i < sqrt(int_n); i++) {
		for (int j = 2; i*j <= int_n; j++)
			bool_che[i*j] = true;
	}
	for (int i = int_m; i <= int_n; i++)
		(!bool_che[i]) ? printf("%d\n", i) : i;

	return 0;
}