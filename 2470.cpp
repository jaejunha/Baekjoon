#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<long long> v;
int n;

bool comp(long long a, long long b) {
	return abs(a) < abs(b);
}

int main() {
	scanf("%d", &n);

	long long t;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t);
		v.push_back(t);
	}

	sort(v.begin(), v.end(), comp);

	long long m = 2000000000;
	long long a, b;

	for (int i = 0; i < n - 1; i++) {
		if (m > abs(v.at(i) + v.at(i + 1))) {
			m = abs(v.at(i) + v.at(i + 1));
			a = v.at(i);
			b = v.at(i + 1);
		}
	}

	if (a > b)
		printf("%lld %lld", b, a);
	else
		printf("%lld %lld", a, b);

	return 0;
}