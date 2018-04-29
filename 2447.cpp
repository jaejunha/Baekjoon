#include <stdio.h>

bool a[6561][6561];
int n;

void fill(int x, int y, int n) {
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					a[x + i][y + j] = false;
				else
					a[x + i][y + j] = true;
			}
		}
	}
	else {
		fill(x, y, n / 3);
		fill(x, y + n, n / 3);
		fill(x, y + 2 * n, n / 3);
		fill(x + n, y, n / 3);
		fill(x + n, y + 2 * n, n / 3);
		fill(x + 2 * n, y, n / 3);
		fill(x + 2 * n, y + n, n / 3);
		fill(x + 2 * n, y + 2 * n, n / 3);
	}
}


int main() {

	scanf("%d", &n);
	if (n == 1) {
		printf("*");
		return 0;
	}
	fill(0, 0, n / 3);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j])
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}