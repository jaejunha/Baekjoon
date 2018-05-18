#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n;
int a[100001][2];
long long s[100001][2];

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int k = 0; k < 2; k++) {
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[j][k]);
		}

		s[1][0] = a[1][0];
		s[1][1] = a[1][1];
		if (n >= 2) {
			s[2][0] = a[2][0] + a[1][1];
			s[2][1] = a[2][1] + a[1][0];
		}
		for (int j = 3; j <= n; j++) {
			s[j][0] = a[j][0] + max(s[j - 2][1], s[j - 1][1]);
			s[j][1] = a[j][1] + max(s[j - 2][0], s[j - 1][0]);
		}
		printf("%lld\n", max(s[n][0], s[n][1]));
	}
	return 0;
}