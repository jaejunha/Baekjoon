#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int m, n;

int gcd(int x, int y) {
	if (!y)
		return x;
	return gcd(y, x%y);
}

int main() {
	scanf("%d%d", &m, &n);
	m = abs(m);
	n = abs(n);
	if (m == n) {
		if (m == 1)
			printf("2");
		else
			printf("%d", m);
	}
	else {
		int a = max(m, n);
		int b = min(m, n);
		printf("%d", gcd(a, b) == 1 ? 1 : 2);
	}
	return 0;
}