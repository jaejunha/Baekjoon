#include <iostream>
using namespace std;

int a[4][8];
int k;

void cycle(int x, int r) {
	if (r == 1) {
		int t = a[x][7];
		for (int i = 7; i >= 1; i--)
			a[x][i] = a[x][i - 1];
		a[x][0] = t;
	}
	else {
		int t = a[x][0];
		for (int i = 0; i < 7; i++)
			a[x][i] = a[x][i + 1];
		a[x][7] = t;
	}
}

void rotateP(int x, int r) {
	int y = x;
	for (int i = x + 1; i <= 3; i++, y++) {
		if (a[i - 1][2] == a[i][6])
			break;
	}
	for (int i = x + 1; i <= y; i++) {
		r = -r;
		cycle(i, r);
	}
}

void rotateM(int x, int r) {
	int y = x;
	for (int i = x - 1; i >= 0; i--, y--) {
		if (a[i + 1][6] == a[i][2])
			break;
	}
	for (int i = x - 1; i >= y; i--) {
		r = -r;
		cycle(i, r);
	}
}

int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int x, r;
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &x, &r);
		x--;
		if (x == 0)
			rotateP(x, r);
		else if (x == 3)
			rotateM(x, r);
		else {
			rotateP(x, r);
			rotateM(x, r);
		}
		cycle(x, r);
	}

	int s = 0;
	if (a[0][0])
		s += 1;
	if (a[1][0])
		s += 2;
	if (a[2][0])
		s += 4;
	if (a[3][0])
		s += 8;
	printf("%d", s);
	return 0;
}