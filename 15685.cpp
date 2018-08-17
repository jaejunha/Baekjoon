#include <iostream>
using namespace std;

int p[101][101], t[101][101];
int s[11];
int c;
int n, x, y, d, g;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int z[1026];

int main() {
	s[0] = 2;
	for (int i = 1; i <= 10; i++) {
		s[i] = 2 * s[i - 1] - 1;
		for (int j = s[i - 1] - 1, k = j - 1; j < s[i] - 1; j++, k--)
			z[j] = (z[k] + 1) % 4;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				t[j][k] = 0;
		scanf("%d%d%d%d", &y, &x, &d, &g);
		for (int i = 0; i < s[g]; i++) {
			t[x][y] = i + 1;
			x += dx[(z[i] + d) % 4];
			y += dy[(z[i] + d) % 4];
		}
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++)
				p[j][k] += t[j][k];
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (p[i][j] && p[i + 1][j] && p[i][j + 1] && p[i + 1][j + 1])
				c++;
		}
	}
	printf("%d", c);

	return 0;
}