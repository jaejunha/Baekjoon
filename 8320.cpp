#include <cstdio>
#include <cmath>
using namespace std;

int n;
long long s;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1, l = sqrt(i); j <= l; j++) {
			if (i%j == 0)
				s++;
		}
	}
	printf("%lld", s);

	return 0;
}