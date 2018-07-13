/* reference: http://simsimjae.tistory.com/227 */
/* reference: http://joonas-yoon.blogspot.com/2016/03/2718.html */
#include <iostream>
using namespace std;

int t, n;
long long dp[1001][13];

long long solve(int x, int b) {
	if (x < 0)
		return 0;
	if (x == 0)
		return 1;
	if (x == 1) {
		if (b == 6)
			return 0;
		else
			return 1;
	}

	long long &ret = dp[x][b];
	if (ret)
		return ret;
	if (b == 0) {
		ret += solve(x - 1, 0);
		ret += solve(x - 2, 0);
		ret += solve(x - 1, 3);
		ret += solve(x - 1, 9);
		ret += solve(x - 1, 12);
	}
	else if (b == 3) {
		ret += solve(x - 1, 0);
		ret += solve(x - 1, 12);
	}
	else if (b == 12) {
		ret += solve(x - 1, 0);
		ret += solve(x - 1, 3);
	}
	else if (b == 6)
		ret += solve(x - 1, 9);
	else if (b == 9) {
		ret += solve(x - 1, 0);
		ret += solve(x - 1, 6);
	}

	return ret;
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		printf("%lld\n", solve(n, 0));
	}

	return 0;
}