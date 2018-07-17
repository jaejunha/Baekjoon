#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	if (b*b - 4 * a*c <= 0) {
		printf("둘다틀렸근");
		return 0;
	}
	double x, y;
	x = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	y = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	if ((x - (int)x != 0) || y - (int)y != 0) {
		printf("둘다틀렸근");
		return 0;
	}
	bool z = true;
	int p = x, q = y;
	while (p) {
		if ((p % 2) && (p != 1))
			z = false;
		p /= 2;
	}
	while (q) {
		if ((q % 2) && (q != 1))
			z = false;
		q /= 2;
	}
	if (z)
		printf("이수근");
	else
		printf("정수근");
	return 0;
}