#include <cstdio>
#include <iostream>
using namespace std;

int n, c, s;
int a[15][15];
bool e;

void dfs() {
	if (c == n)
		s++;
	else {
		for (int i = 0; i < n; i++) {
			if (!a[c][i]) {
				e = false;
				for (int x = c - 1, y = 1; x >= 0; x--, y++) {
					if (i - y >= 0 && a[x][i - y]) {
						e = true;
						break;
					}
					if (i + y < n && a[x][i + y]) {
						e = true;
						break;
					}
					if (a[x][i]) {
						e = true;
						break;
					}
				}
				if (e)
					continue;
				a[c++][i] = 1;
				dfs();
			}
		}
	}

	c--;
	for (int i = 0; i < n; i++)
		a[c][i] = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				a[x][y] = 0;
		c = 1;
		a[0][i] = 1;
		dfs();
	}
	printf("%d", s);
	return 0;
}