#include <iostream>
#include <cmath>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	for (int i = 2, l = sqrt(n); i <= l; i++) {
		while (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n != 1)
		printf("%d", n);
	return 0;
}