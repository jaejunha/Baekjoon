#include <iostream>
#include <algorithm>
using namespace std;

double a, b, c, i, j, k, m;
int main() {
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &i, &j, &k);
	m = min(a / i, min(b / j, c / k));
	printf("%lf %lf %lf", a - i*m, b - j*m, c - k*m);

	return 0;
}