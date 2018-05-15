#include <stdio.h>
#include <algorithm>

using namespace std;

int a[10][10];
int s[10][10];
int w, h;

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0, t; j < w; j++) {
			scanf("%d", &t);
			a[i][j] -= t;
			a[i][j] *= a[i][j];
		}
	}

	for (int i = 0; i < w; i++)
		s[0][i] = a[0][i];

	if (w > 1) {
		for (int i = 1; i < h; i++) {
			s[i][0] = min(s[i - 1][0], s[i - 1][1]) + a[i][0];
			for (int j = 1; j < w - 1; j++)
				s[i][j] = min(min(s[i - 1][j - 1], s[i - 1][j]), s[i - 1][j + 1]) + a[i][j];
			s[i][w - 1] = min(s[i - 1][w - 2], s[i - 1][w - 1]) + a[i][w - 1];
		}

		int t = 99999999;
		for (int i = 0; i < w; i++)
			t = min(t, s[h - 1][i]);

		printf("%d", t);
	}
	else {
		int s = 0;
		for (int i = 0; i < h; i++)
			s += a[i][0];
		printf("%d", s);
	}
	return 0;
}