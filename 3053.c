#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int n;
double a;
int main() {
	scanf("%d", &n);
	a = PI * n*n;
	printf("%.6lf\n", a);

	a = 2 * n*n;
	printf("%.6lf\n", a);

	return 0;
}