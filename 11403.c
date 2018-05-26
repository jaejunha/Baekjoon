#include <stdio.h>

int a[101][101];
int n;

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] && a[k][j])
					a[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}