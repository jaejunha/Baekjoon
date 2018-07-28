#include <iostream>
using namespace std;

int n, m, k, a, b, c;
long long v[1000001];
long long tree[1000001];
void update(int i, long long num) {
	while (i <= n) {
		tree[i] += num;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
		update(i, v[i]);
	}
	for (int i = 1, l = m + k; i <= l; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			update(b, c - v[b]);
			v[b] = c;
		}
		else
			printf("%lld\n", sum(c) - sum(b - 1));

	}
	return 0;
}