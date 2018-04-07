#include <stdio.h>

int n, k;
int a[10];
int c = 0;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = n - 1; i >= 0; i--) {
		while (a[i] <= k) {
			k -= a[i];
			c++;
		}
	}

	printf("%d", c);

	return 0;
}