#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int r[101][101];
int sum = 100000;
int answer;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			r[i][j] = 100000;
	for (int x, y; m--;) {
		scanf("%d%d", &x, &y);
		r[x][y] = r[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				r[j][k] = min(r[j][k], r[j][i] + r[i][k]);
			}
		}
	}

	for (int i = 1, s; i <= n; i++) {
		s = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			s += r[i][j];
		}

		if (sum > s) {
			sum = s;
			answer = i;
		}
	}
	printf("%d", answer);
	return 0;
}