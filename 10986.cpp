/* reference: http://donggod.tistory.com/77 */
#include <iostream>

using namespace std;

long long n, m, c;
long long r[1000];
long long s;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		s = (s + x) % m;
		r[s]++;
		if (!s)
			c++;
	}
	for (long long x : r)
		c += x*(x - 1) / 2;
	printf("%lld", c);
	return 0;
}