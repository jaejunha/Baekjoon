#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long s;
int n;

int main() {
	scanf("%lld", &s);
	double r = (-1 + sqrt(1 + 8 * s)) / 2;
	printf("%d", (int)r);
	return 0;
}