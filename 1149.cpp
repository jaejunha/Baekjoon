#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[1001][3];
int s[1001][3];

int main() {


	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <3; j++)
			scanf("%d", &a[i][j]);
	}

	s[1][0] = a[1][0];
	s[1][1] = a[1][1];
	s[1][2] = a[1][2];

	for (int i = 2; i <= n; i++) {
		s[i][0] = a[i][0] + min(s[i - 1][1], s[i - 1][2]);
		s[i][1] = a[i][1] + min(s[i - 1][0], s[i - 1][2]);
		s[i][2] = a[i][2] + min(s[i - 1][0], s[i - 1][1]);
	}
	int m = 9999999;
	for (int i = 0; i < 3; i++)
		m = min(m, s[n][i]);
	printf("%d\n", m);
	return 0;
}