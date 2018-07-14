/* reference: http://js1jj2sk3.tistory.com/42 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, p, s;
int a[17][17];
int dp[65536];

int solve(int v, int r) {
	if (r <= 0)
		return 0;

	int &ret = dp[v];
	if (ret != -1)
		return ret;
	ret = 1000000;

	for (int i = 1; i <= n; i++) {
		if (v&(1 << (i - 1))) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				if (!(v&(1 << (j - 1))))
					ret = min(ret, solve(v | (1 << (j - 1)), r - 1) + a[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	int b = 0, on = 0;
	char c;
	scanf("%c", &c);
	for (int i = 1, j = 1; i <= n; i++, j <<= 1) {
		scanf("%c", &c);
		if (c == 'Y') {
			b |= j;
			on++;
		}
	}
	scanf("%d", &p);

	if (!on) {
		if (!p)
			printf("0");
		else
			printf("-1");
	}
	else if (on >= p)
		printf("0");
	else {
		for (int i = 0, l = 1 << n; i < l; i++)
			dp[i] = -1;
		printf("%d", solve(b, p - on));
	}
	return 0;
}