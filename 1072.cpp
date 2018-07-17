/* reference: https://github.com/kks227/BOJ/blob/master/1000/1072.cpp */
#include <cstdio>
#include <algorithm>
using namespace std;

long long x, y, z;
int main() {
	while (scanf("%lld %lld", &x, &y) != EOF) {
		z = 100 * y / x;
		if (z >= 99)
			printf("-1\n");
		else {
			long long m = (x*z + x - (long long)100 * y) / (99 - z);
			if ((x*z + x - (long long)100 * y) % (99 - z))
				m++;

			printf("%lld\n", m);
		}
	}
	return 0;
}