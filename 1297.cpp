#include <iostream>
#include <cmath>
using namespace std;
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	double d = a / sqrt(b*b + c*c);
	printf("%d %d", (int)(b*d), (int)(c*d));
	return 0;
}