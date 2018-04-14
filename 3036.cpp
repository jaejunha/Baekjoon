#include <stdio.h>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	long long x, y, r;
	x = max(a, b);
	y = min(a, b);
	r = x % y;

	while (r > 0) {
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

int main() {

	int n;
	int a, b;
	scanf("%d", &n);
	for (int i = 0, j; i < n; i++) {
		if (i == 0)
			scanf("%d", &a);
		else {
			scanf("%d", &b);
			j = gcd(a, b);
			printf("%d/%d\n", a / j, b / j);
		}
	}

	return 0;
}