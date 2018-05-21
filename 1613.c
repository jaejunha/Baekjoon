#include <stdio.h>

int n, s;
int z[401][401];

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1, a, b; i <= s; i++) {
		scanf("%d %d", &a, &b);
		z[a][b] = -1;
		z[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (z[j][i] && (z[j][i] == z[i][k]))
					z[j][k] = z[j][i];
			}
		}
	}

	scanf("%d", &s);
	for (int i = 1, a, b, t; i <= s; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", z[a][b]);
	}
	return 0;
}