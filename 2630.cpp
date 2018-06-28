#include <cstdio>
using namespace std;

int n;
int a[128][128];
int w, b;

int dfs(int x, int y, int m) {
	if (m == 1)
		return a[x][y];

	int s[4], t, c = m * m;
	s[0] = dfs(x, y, m / 2);
	s[1] = dfs(x + m / 2, y, m / 2);
	s[2] = dfs(x, y + m / 2, m / 2);
	s[3] = dfs(x + m / 2, y + m / 2, m / 2);

	t = s[0] + s[1] + s[2] + s[3];
	if (t != c && t != 0) {
		for (int i = 0, d = c / 4; i < 4; i++) {
			if (s[i] == d)
				b++;
			else if (s[i] == 0) {
				w++;
			}
		}
	}
	return t;
}

int main() {
	scanf("%d", &n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j])
				c++;
		}
	}
	if (c == n*n)
		b = c;
	else if (c == 0)
		w = n*n;
	else
		dfs(0, 0, n);
	printf("%d\n%d", w, b);
	return 0;
}