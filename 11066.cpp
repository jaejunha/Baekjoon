#include <stdio.h>
#include <algorithm>

using namespace std;

int f[501][501];
int a[501];
int s[501];

int main() {
	int n;
	int m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[j]);
			s[j] = s[j - 1] + a[j];
		}

		for (int j = 1; j < m; j++) {
			for (int k = 1, local; k + j <= m; k++) {
				local = 100000000;
				for (int l = k; l < k + j; l++)
					local = min(local, f[k][l] + f[l + 1][k + j] + s[k + j] - s[k - 1]);
				f[k][k + j] = local;
			}
		}

		printf("%d\n", f[1][m]);
	}
	return 0;
}