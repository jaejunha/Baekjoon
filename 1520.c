#include <stdio.h>

int w, h;
int a[500][500];
int s[500][500];

int cal(int x, int y) {

	if (x == 0 && y == 0) {
		s[y][x] = 1;
		return 1;
	}
	s[y][x] = 0;

	if (x > 0) {
		if (a[y][x - 1] > a[y][x]) {
			if (s[y][x - 1] == -1)
				s[y][x - 1] = cal(x - 1, y);
			s[y][x] += s[y][x - 1];
		}
	}
	if (x < w - 1) {
		if (a[y][x + 1] > a[y][x]) {
			if (s[y][x + 1] == -1)
				s[y][x + 1] = cal(x + 1, y);
			s[y][x] += s[y][x + 1];
		}
	}
	if (y > 0) {
		if (a[y - 1][x] > a[y][x]) {
			if (s[y - 1][x] == -1)
				s[y - 1][x] = cal(x, y - 1);
			s[y][x] += s[y - 1][x];
		}
	}
	if (y < h - 1) {
		if (a[y + 1][x] > a[y][x]) {
			if (s[y + 1][x] == -1)
				s[y + 1][x] = cal(x, y + 1);
			s[y][x] += s[y + 1][x];
		}
	}

	return s[y][x];
}

int main() {

	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
			s[i][j] = -1;
		}
	}

	s[0][0] = 1;
	printf("%d", cal(w - 1, h - 1));

	return 0;
}