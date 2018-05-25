/* reference: http://yukari-ko.blogspot.kr/2014/08/1695.html */

#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
char a[5001];

int dp[5001][5001];

int p(int s, int e) {
	if (s >= e)
		return 0;

	if (dp[s][e])
		return dp[s][e];

	if (a[s] == a[e])
		return (dp[s][e] = p(s + 1, e - 1));
	else
		return (dp[s][e] = (min(p(s + 1, e), p(s, e - 1)) + 1));
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i <= n; scanf("%c", &a[i++]));
	printf("%d", p(1, n));

	return 0;
}