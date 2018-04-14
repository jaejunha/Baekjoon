#include <stdio.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	int x, y, r;
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

int n;
int main() {

	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b / gcd(a, b));
	}

	return 0;
}