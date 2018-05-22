#include <stdio.h>

int z[101][101];
int n, m;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				z[i][j] = 0;
			else
				z[i][j] = 200001;
		}
	}

	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (z[a][b]>c)
			z[a][b] = c;
	}

	for (int i = 1, a; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a = z[j][i] + z[i][k];
				if (z[j][k] > a)
					z[j][k] = a;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (z[i][j] == 200001)
				printf("0 ");
			else
				printf("%d ", z[i][j]);
		}
		printf("\n");
	}
	return 0;
}