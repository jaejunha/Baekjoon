#include <iostream>
using namespace std;

long long n;
long long m = 10;

int main() {
	scanf("%lld", &n);
	if (n < 10)
		printf("%d", n);
	else {
		while (n > m) {
			if (n%m >= 5 * m / 10)
				n += (m - n%m);
			else
				n -= (n%m);
			m *= 10;
		}
		printf("%d", n);
	}
	return 0;
}