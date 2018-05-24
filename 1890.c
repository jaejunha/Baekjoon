/* reference: http://mygumi.tistory.com/198 */
#include <stdio.h>

int n;
int a[101][101];
long long s[101][101];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}

	s[1][1] = 1;
	for (int i = 1, pi, pj; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n)
				continue;
			pj = a[i][j] + j;
			pi = a[i][j] + i;
			if (pi <= n)
				s[pi][j] += s[i][j];
			if (pj <= n)
				s[i][pj] += s[i][j];
		}
	}
	printf("%lld", s[n][n]);
	return 0;
}