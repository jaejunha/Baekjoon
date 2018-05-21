#include <stdio.h>
#include <math.h>

int n, x, y, max;
int a[128][128];
int value = 1;

void tile(int o_x, int o_y, int x, int y, int dir, int n) {
	if (n == 1) {
		int p_x = dir % 2, p_y = 1 - ((dir - 1) / 2);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == p_y && j == p_x)
					continue;
				a[o_y + i][o_x + j] = value;
			}
		}
		value++;
		return;
	}

	int d = pow(2, n - 1);
	if (dir == 4)
		tile(o_x, o_y, x, y, 4, n - 1);
	else
		tile(o_x, o_y, x, y, 1, n - 1);
	if (dir == 3)
		tile(o_x + d, o_y, x, y, 3, n - 1);
	else
		tile(o_x + d, o_y, x, y, 2, n - 1);
	if (dir == 2)
		tile(o_x, o_y + d, x, y, 2, n - 1);
	else
		tile(o_x, o_y + d, x, y, 3, n - 1);
	if (dir == 1)
		tile(o_x + d, o_y + d, x, y, 1, n - 1);
	else
		tile(o_x + d, o_y + d, x, y, 4, n - 1);

	if (dir != 4)
		a[o_y + d - 1][o_x + d - 1] = value;
	if (dir != 3)
		a[o_y + d - 1][o_x + d] = value;
	if (dir != 2)
		a[o_y + d][o_x + d - 1] = value;
	if (dir != 1)
		a[o_y + d][o_x + d] = value;
	value++;
}

void setting(int o_x, int o_y, int n) {
	if (n == 1)
		return;

	int d = pow(2, n - 1);
	int dir = ((x < o_x + d) ? 1 : 2) + ((y < o_y + d) ? 0 : 2);

	for (int i = 1, j = d; i <= 4; i++) {
		if (i == dir)
			continue;
		else
			tile(o_x + (1 - i % 2)*j, o_y + (int)((i - 1) / 2)*j, x, y, i, n - 1);
	}
	for (int i = 1, j = d; i <= 4; i++) {
		if (i == dir) continue;
		a[o_y + j - 1 + (i - 1) / 2][o_x + j - i % 2] = value;
	}
	value++;
	if (dir == 1)
		setting(o_x, o_y, n - 1);
	else if (dir == 2)
		setting(o_x + d, o_y, n - 1);
	else if (dir == 3)
		setting(o_x, o_y + d, n - 1);
	else if (dir == 4)
		setting(o_x + d, o_y + d, n - 1);
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	max = pow(2, n);
	x = x - 1;
	y = max - y;
	if (n == 1) {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				if ((i == y) && (j == x))
					printf("-1 ");
				else
					printf("1 ");
			}
			printf("\n");
		}
	}
	else {
		setting(0, 0, n);
		value++;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++)
				a[y - (y % 2) + i][x - (x % 2) + j] = value;
		}
		value++;
		a[y][x] = -1;
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}