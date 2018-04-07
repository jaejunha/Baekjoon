#include <stdio.h>

int n, k;
int s = 1;
int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++)
		s *= n--;
	for (int i = 1; i <= k; i++)
		s /= i;

	printf("%d", s);

	return 0;
}