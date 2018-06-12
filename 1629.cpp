/* reference: https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/ */
#include <cstdio>

using namespace std;

long long a, b, c, t, s = 1;

int main() {
	scanf("%lld%lld%lld", &a, &b, &c);
	a %= c;
	t = a;
	while (b) {
		if (b % 2) {
			s *= t;
			s %= c;
		}
		t *= t;
		t %= c;
		b /= 2;
	}
	printf("%lld", s);

	return 0;
}