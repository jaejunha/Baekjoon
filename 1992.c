#include <stdio.h>

int n;
int a[100][100];

void solve(int x, int y, int s) {
	if (s == 0)
		return;

	int sum = 0;
	for (int i = x, m_x = x + s; i < m_x; i++)
		for (int j = y, m_y = y + s; j < m_y; j++)
			if (a[i][j])
				sum++;

	if (sum == s * s)
		printf("1");
	else if (sum == 0)
		printf("0");
	else {
		printf("(");
		solve(x, y, s / 2);
		solve(x, y + s / 2, s / 2);
		solve(x + s / 2, y, s / 2);
		solve(x + s / 2, y + s / 2, s / 2);
		printf(")");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &a[i][j]);

	solve(0, 0, n);

	return 0;
}