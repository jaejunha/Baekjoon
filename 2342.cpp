/* reference: http://tastyprogramming.tistory.com/9 */
#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100001][5][5], sol = 400000;
int n, l;

int f(int x, int y) {
	if (x == y)
		return 1;
	else if (x == 0 || y == 0)
		return 2;
	else if (abs(y - x) == 2)
		return 4;
	else
		return 3;
}

int main() {
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = 400000;
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		l++;
		if (l == 1) {
			dp[1][n][0] = 2;
			dp[1][0][n] = 2;
		}
		else {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					dp[l][i][n] = min(dp[l][i][n], dp[l - 1][i][j] + f(n, j));
					dp[l][n][i] = min(dp[l][n][i], dp[l - 1][j][i] + f(n, j));
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			sol = min(sol, dp[l][i][j]);
	}
	printf("%d", sol);
	return 0;
}