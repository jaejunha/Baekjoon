#include <stdio.h>

long long a, b, v;

int main() {
	scanf("%lld%lld%lld", &a, &b, &v);
	printf("%lld", ((v - b) / (a - b)) + ((v - b) % (a - b) ? 1 : 0));

	return 0;
}