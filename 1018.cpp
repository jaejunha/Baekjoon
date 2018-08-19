#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, s;
char a[51][51];
char p[] = "WB";

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s);
		for (int j = 1; j <= m; j++)
			scanf("%c", &a[i][j]);
	}
	s = 64;
	for (int i = 1; i <= n - 7; i++) {
		for (int j = 1; j <= m - 7; j++) {
			int c = 0;
			for (int x = i, l_x = i + 7; x <= l_x; x++) {
				for (int y = j, l_y = j + 7; y <= l_y; y++) {
					if (a[x][y] != p[(x + y) % 2])
						c++;
				}
			}
			c = min(c, 64 - c);
			s = min(s, c);
		}
	}
	printf("%d", s);

	return 0;
}