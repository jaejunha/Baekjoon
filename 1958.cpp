#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
char a[101], b[101], c[101];
int s[101][101][101];

void lcs(char f[], char g[], char h[]) {
	int lf = strlen(f), lg = strlen(g), lh = strlen(h);
	for (int i = 1; i <= lf; i++) {
		for (int j = 1; j <= lg; j++) {
			for (int k = 1; k <= lh; k++) {
				if (f[i - 1] == g[j - 1] && f[i - 1] == h[k - 1])
					s[i][j][k] = s[i - 1][j - 1][k - 1] + 1;
				else
					s[i][j][k] = max(max(s[i - 1][j][k], s[i][j - 1][k]), s[i][j][k - 1]);
			}
		}
	}
	printf("%d", s[lf][lg][lh]);
}

int main() {
	scanf("%s\n%s\n%s", a, b, c);
	lcs(a, b, c);
	return 0;
}