#include <iostream>
#include <algorithm>
using namespace std;

int n, t, s;
char a[51][51];

void c(int x, int y) {
	int z = 1;
	for (int i = y + 1; i <= n; i++) {
		if (a[x][y] == a[x][i])
			z++;
		else
			break;
	}
	for (int i = y - 1; i >= 1; i--) {
		if (a[x][y] == a[x][i])
			z++;
		else
			break;
	}
	s = max(s, z);
}

void r(int x, int y) {
	int z = 1;
	for (int i = x + 1; i <= n; i++) {
		if (a[x][y] == a[i][y])
			z++;
		else
			break;
	}
	for (int i = x - 1; i >= 1; i--) {
		if (a[x][y] == a[i][y])
			z++;
		else
			break;
	}
	s = max(s, z);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &t);
		for (int j = 1; j <= n; j++)
			scanf("%c", &a[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - 1; j++) {
			swap(a[i][j], a[i][j + 1]);
			c(i, j);
			c(i, j + 1);
			r(i, j);
			r(i, j + 1);
			swap(a[i][j], a[i][j + 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - 1; j++) {
			swap(a[j][i], a[j + 1][i]);
			c(j, i);
			c(j + 1, i);
			r(j, i);
			r(j + 1, i);
			swap(a[j][i], a[j + 1][i]);
		}
	}

	printf("%d", s);
	return 0;
}