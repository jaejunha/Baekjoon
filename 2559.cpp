#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long ps[100001];
long long s;
long long ans = -100 * 100000 - 1;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1, j; i <= n; i++) {
		scanf("%d", &j);
		s += j;
		ps[i] = s;
	}

	for (int i = 1, l = n - k + 1; i <= l; i++)
		ans = max(ans, ps[i + k - 1] - ps[i - 1]);
	printf("%lld", ans);
	return 0;
}