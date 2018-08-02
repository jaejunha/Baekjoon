/* reference: http://codersbrunch.blogspot.com/2016/12/13711-lcs-4.html */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100001];
int dp[100000];

int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		a[x] = i;
	}
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		dp[i] = n;
		*lower_bound(dp, dp + i, a[x]) = a[x];
	}

	printf("%d", lower_bound(dp, dp + n, n) - dp);
	return 0;
}