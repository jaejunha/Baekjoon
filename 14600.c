#include <stdio.h>

int n, x, y;
int a[4][4];

int main() {
	scanf("%d", &n);
	scanf("%d %d", &x, &y);

	if (n == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if ((i == 2 - y) && (j == x - 1))
					printf("-1 ");
				else
					printf("1 ");
			}
			printf("\n");
		}
	}
	else {
		for (int i = 1; i < 3; i++)
			for (int j = 1; j < 3; j++)
				a[i][j] = 5;
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[0][2] = a[0][3] = a[1][3] = 2;
		a[2][0] = a[3][0] = a[3][1] = 3;
		a[2][3] = a[3][3] = a[3][2] = 4;
		if (y <= 2) {
			if (x <= 2)
				a[2][1] = 3;
			else
				a[2][2] = 4;
		}
		else {
			if (x <= 2)
				a[1][1] = 1;
			else
				a[1][2] = 2;
		}
		a[4 - y][x - 1] = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}