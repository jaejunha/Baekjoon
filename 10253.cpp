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

int main() {
	int n;
	int a, b;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = 2, g;; j++) {
			if (b == j) {
				if (a != 1)
					continue;
				else {
					printf("%d\n", b);
					break;
				}
			}
			if ((double)a / b>1.0 / j) {
				g = gcd(b, j);
				a = (a * j) / g - b / g;
				b = b * j / g;
				g = gcd(a, b);
				a /= g;
				b /= g;
				if (a == 1) {
					printf("%d\n", b);
					break;
				}
			}
		}
	}

	return 0;
}