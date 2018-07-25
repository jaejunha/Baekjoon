#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
char a[101][101], t;
int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%c", &a[i][j]);
		scanf("%c", &t);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= 2 && a[i][j] == '.' && a[i][j - 1] == '.') {
				s++;
				while (j != n && a[i][j + 1] == '.')
					j++;
			}
		}
	}
	printf("%d ", s);
	s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= 2 && a[j][i] == '.' && a[j - 1][i] == '.') {
				s++;
				while (j != n && a[j + 1][i] == '.')
					j++;
			}
		}
	}
	printf("%d", s);
	return 0;
}