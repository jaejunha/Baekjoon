#include <stdio.h>

int n;
int t[2187][2187];
int a, b, c;

int solve(int i, int j, int s) {
	if (s == 1)
		return t[i][j];
	int c_a = 0, c_b = 0, c_c = 0;

	for (int k = 0; k < 3; k++)
		for (int l = 0, r; l < 3; l++) {
			r = solve(i + k * s / 3, j + l * s / 3, s / 3);
			if (r == -1)
				c_a++;
			else if (r == 0)
				c_b++;
			else if (r == 1)
				c_c++;
		}
	if (c_a == 9)
		return -1;
	else if (c_b == 9)
		return 0;
	else if (c_c == 9)
		return 1;
	else {
		a += c_a;
		b += c_b;
		c += c_c;
		return 9;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &t[i][j]);
	int r = solve(0, 0, n);
	if (r == -1) a = 1;
	else if (r == 0) b = 1;
	else if (r == 1) c = 1;
	printf("%d\n%d\n%d", a, b, c);
	return 0;
}