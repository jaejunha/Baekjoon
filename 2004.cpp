/* reference: http://ksj14.tistory.com/entry/BackJoon2004-%EC%A1%B0%ED%95%A9-0%EC%9D%98-%EA%B0%9C%EC%88%98 */
#include <cstdio>
#include <algorithm>
using namespace std;

long long n, m, k;
long long a, b;

int main() {
	scanf("%lld%lld", &n, &m);
	for (long long i = 2; i <= n; i *= 2)
		a += n / i;

	for (long long i = 5; i <= n; i *= 5)
		b += n / i;

	for (long long i = 2; i <= m; i *= 2)
		a -= m / i;

	for (long long i = 5; i <= m; i *= 5)
		b -= m / i;

	k = n - m;
	for (long long i = 2; i <= k; i *= 2)
		a -= k / i;

	for (long long i = 5; i <= k; i *= 5)
		b -= k / i;
	printf("%lld", min(a, b));
	return 0;
}