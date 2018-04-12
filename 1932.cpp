#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[501][501];
int b[501][501];

int main() {


	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			scanf("%d", &b[i][j]);
	}

	a[1][1] = b[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i)
				a[i][j] = a[i - 1][j - 1] + b[i][j];
			else if (j == 1)
				a[i][j] = a[i - 1][j] + b[i][j];
			else
				a[i][j] = max(a[i - 1][j - 1] + b[i][j], a[i - 1][j] + b[i][j]);
		}
	}
	int m = 0;
	for (int i = 1; i <= n; i++) {
		m = max(m, a[n][i]);
	}
	printf("%d\n", m);
	return 0;
}