#include <cstdio>
int t, x[2], y[2], r[2];
double d, left, right;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d", &x[0], &y[0], &r[0], &x[1], &y[1], &r[1]);
		d = (x[1] - x[0])*(x[1] - x[0]) + (y[1] - y[0])*(y[1] - y[0]);
		left = (r[1] - r[0])*(r[1] - r[0]);
		right = (r[1] + r[0])*(r[1] + r[0]);
		if (x[1] == x[0] && y[0] == y[1] && r[0] == r[1])
			printf("-1\n");
		else if (d > right || d < left)
			printf("0\n");
		else if (d == left || d == right)
			printf("1\n");
		else if (d > left && d < right)
			printf("2\n");
		else
			printf("-1\n");
	}

	return 0;
}