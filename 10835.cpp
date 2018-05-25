#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n, a[1001];
int dp[1001][1001];
int ep[1001][1001];

int tol(int s, int e);

int sol(int s, int e) {
	if (s > e)
		return 0;
	if (s == e)
		return a[s];

	if (dp[s][e])
		return dp[s][e];

	return (dp[s][e] = max(a[s] + tol(s + 1, e), a[e] + tol(s, e - 1)));
}

int tol(int s, int e) {
	if (s >= e)
		return 0;

	if (ep[s][e])
		return ep[s][e];

	return (ep[s][e] = min(sol(s + 1, e), sol(s, e - 1)));
}

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", sol(1, n));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
				ep[i][j] = 0;
			}
		}
	}
	return 0;
}