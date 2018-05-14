#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[3];

int mx[100001][3], mn[100001][3];
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%1d %1d %1d", &a[0], &a[1], &a[2]);
		if (i == 1) {
			for (int j = 0; j < 3; j++)
				mx[1][j] = mn[1][j] = a[j];
		}
		else {
			mx[i][0] = max(mx[i - 1][0], mx[i - 1][1]) + a[0];
			mx[i][1] = max(max(mx[i - 1][0], mx[i - 1][1]), mx[i - 1][2]) + a[1];
			mx[i][2] = max(mx[i - 1][1], mx[i - 1][2]) + a[2];
			mn[i][0] = min(mn[i - 1][0], mn[i - 1][1]) + a[0];
			mn[i][1] = min(min(mn[i - 1][0], mn[i - 1][1]), mn[i - 1][2]) + a[1];
			mn[i][2] = min(mn[i - 1][1], mn[i - 1][2]) + a[2];
		}
	}

	printf("%d %d", max(max(mx[n][0], mx[n][1]), mx[n][2]), min(min(mn[n][0], mn[n][1]), mn[n][2]));
	return 0;
}