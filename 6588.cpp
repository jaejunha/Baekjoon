#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool c[1000001];

int main() {
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2 * i; j <= 1000000; j += i)
			c[j] = true;
	}

	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		int m = n / 2;
		for (int i = 3; i <= m; i++) {
			if (!c[i] && !c[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
	return 0;
}