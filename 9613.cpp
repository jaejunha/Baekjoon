#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int n, a[100];
long long s;

int gcd(int a, int b) {
	int mx = max(a, b);
	int mn = min(a, b);
	int r;
	do {
		r = mx % mn;
		mx = mn;
		mn = r;
	} while (mn);
	return mx;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		s = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++)
				s += gcd(a[i], a[j]);
		}
		printf("%lld\n", s);
	}
	return 0;
}