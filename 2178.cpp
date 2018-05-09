#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
int a[101][101];

queue<pair<int, int>> q;

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	q.push(make_pair(1, 1));
	pair<int, int> p;
	int i, j;
	while (!q.empty()) {
		p = q.front();
		i = p.first;
		j = p.second;
		q.pop();

		if (i == m && j == n)
			break;

		if (i > 1 && a[i - 1][j] == 1) {
			a[i - 1][j] = a[i][j] + 1;
			q.push(make_pair(i - 1, j));
		}
		if (i < m && a[i + 1][j] == 1) {
			a[i + 1][j] = a[i][j] + 1;
			q.push(make_pair(i + 1, j));
		}
		if (j > 1 && a[i][j - 1] == 1) {
			a[i][j - 1] = a[i][j] + 1;
			q.push(make_pair(i, j - 1));
		}
		if (j < n && a[i][j + 1] == 1) {
			a[i][j + 1] = a[i][j] + 1;
			q.push(make_pair(i, j + 1));
		}
	}

	printf("%d", a[m][n]);

	return 0;
}