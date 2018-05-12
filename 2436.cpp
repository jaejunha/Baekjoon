#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<pair<long long, pair<long long, long long>>> v;

long long g, l;

long long gcd(long long i, long long j) {
	long long r;
	long long a = max(i, j);
	long long b = min(i, j);
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	scanf("%lld %lld", &g, &l);

	if (g == l) {
		printf("%lld %lld", g, g);
		return 0;
	}

	for (long long i = g, j, k = sqrt(l*g); i <= k; i += g) {
		j = l * g / i;
		if (j % g == 0 && gcd(i, j) == g && (i*j / g == l)) {
			v.push_back({ i + j,{ i, j } });
		}
	}

	sort(v.begin(), v.end());
	printf("%lld %lld", min(v[0].second.first, v[0].second.second), max(v[0].second.first, v[0].second.second));

	return 0;
}