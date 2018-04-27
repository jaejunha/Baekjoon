#include <stdio.h>

int n;
int a[50];
int b[50];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; scanf("%d", &a[i++]));
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				b[i]++;
			else
				b[j]++;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	return 0;
}