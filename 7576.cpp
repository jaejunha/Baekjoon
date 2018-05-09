#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
int a[1001][1001];
int remain;
int counter;

queue<pair<pair<int, int>, int>> q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
				q.push(make_pair(make_pair(i, j), 1));
			if (a[i][j] == 0)
				remain++;
		}
	}

	if (remain == 0) {
		printf("0");
		return 0;
	}
	pair<pair<int, int>, int> p;
	int i, j, k;
	while (!q.empty()) {
		p = q.front();
		i = p.first.first;
		j = p.first.second;
		k = p.second;
		q.pop();
		counter = k;

		if (i > 1 && a[i - 1][j] == 0) {
			a[i - 1][j] = 1;
			q.push(make_pair(make_pair(i - 1, j), k + 1));
			remain--;
		}
		if (i < m && a[i + 1][j] == 0) {
			a[i + 1][j] = 1;
			q.push(make_pair(make_pair(i + 1, j), k + 1));
			remain--;
		}
		if (j > 1 && a[i][j - 1] == 0) {
			a[i][j - 1] = 1;
			q.push(make_pair(make_pair(i, j - 1), k + 1));
			remain--;
		}
		if (j < n && a[i][j + 1] == 0) {
			a[i][j + 1] = 1;
			q.push(make_pair(make_pair(i, j + 1), k + 1));
			remain--;
		}
	}

	if (remain > 0)
		printf("-1");
	else
		printf("%d", counter - 1);

	return 0;
}