#include <iostream>
using namespace std;

long long a, b;
int main() {
	scanf("%lld%lld", &a, &b);
	printf("%lld", (a + b)*(abs(b - a) + 1) / 2);
	return 0;
}