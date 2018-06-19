#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[50][50];
int s = 1;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; (j + k < m) && (i + k < n); k++) {
				if (a[i][j] == a[i + k][j]) {
					if (a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j + k])
						s = max(s, k + 1);
				}
			}
		}
	}

	printf("%d", s*s);

	return 0;
}