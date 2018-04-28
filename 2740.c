#include <stdio.h>

int a[101][101];
int b[101][101];
int c[101][101];

int n, m, k;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			scanf("%d", &b[i][j]);

	for (int i = 0; i <n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < m; l++)
				c[i][j] += a[i][l] * b[l][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	return 0;
}