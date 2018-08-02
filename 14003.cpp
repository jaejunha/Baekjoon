#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
int a[1000001];
int dp[1000001];
int p[1000001];
vector<int> v;

int main() {
	scanf("%d", &n);
	for (int i = 0, j; i < n; i++) {
		scanf("%d", &a[i]);
		dp[i] = 1000000001;
		j = lower_bound(dp, dp + i, a[i]) - dp;
		if (dp[j] == 1000000001)
			c++;
		dp[j] = a[i];
		p[i] = j;
	}
	printf("%d\n", c);
	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == c - 1) {
			v.push_back(a[i]);
			c--;
		}
	}

	for (int i = v.size() - 1; i >= 0; i--)
		printf("%d ", v[i]);
	return 0;
}