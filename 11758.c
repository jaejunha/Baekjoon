#include <stdio.h>

int x[3], y[3];

int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);

	int s = x[0] * y[1] + x[1] * y[2] + x[2] * y[0] - (y[0] * x[1] + y[1] * x[2] + y[2] * x[0]);
	if (s > 0)
		printf("1");
	else if (s == 0)
		printf("0");
	else
		printf("-1");
	return 0;
}