#include <cstdio>

int a, b, c;

int main() {

	scanf("%d%d%d", &a, &b, &c);
	if (a == b + c)
		printf("%d=%d+%d", a, b, c);
	else if (a == b * c)
		printf("%d=%d*%d", a, b, c);
	else if (a == b - c)
		printf("%d=%d-%d", a, b, c);
	else if (a == b / c)
		printf("%d=%d/%d", a, b, c);
	else if (a + b == c)
		printf("%d+%d=%d", a, b, c);
	else if (a - b == c)
		printf("%d-%d=%d", a, b, c);
	else if (a * b == c)
		printf("%d*%d=%d", a, b, c);
	else if (a / b == c)
		printf("%d/%d=%d", a, b, c);
	return 0;
}