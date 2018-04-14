#include <stdio.h>
#include <algorithm>

using namespace std;

int **a;

int calSpace(int number) {
	int t = number;
	int s = 0;
	while (t > 0) {
		t /= 10;
		s++;
	}
	return s;
}


int main() {

	int number = 1;
	int x = 5000;
	int y = 5000;
	int n = 1;
	int limit;
	int space = 0;
	int size;
	int condition;
	int r1, r2, c1, c2;
	int mr1, mr2, mc1, mc2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	a = new int*[c2 - c1 + 1];
	for (int i = 0; i < c2 - c1 + 1; i++)
		a[i] = new int[r2 - r1 + 1];
	mr1 = r1 + 5000;
	mr2 = r2 + 5000;
	mc1 = c1 + 5000;
	mc2 = c2 + 5000;


	size = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));
	condition = 4 * size*size;

	if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
		a[x - mc1][y - mr1] = number;
		space = max(space, calSpace(number));
	}
	x++;
	number++;
	while (number<condition) {
		limit = 2 * n - 1;
		for (int i = 0; i < limit; i++) {
			if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
				a[x - mc1][y - mr1] = number;
				space = max(space, calSpace(number));
			}
			y--;
			number++;
		}
		if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
			a[x - mc1][y - mr1] = number;
			space = max(space, calSpace(number));
		}
		x--;
		number++;
		for (int i = 0; i < limit; i++) {
			if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
				a[x - mc1][y - mr1] = number;
				space = max(space, calSpace(number));
			}
			x--;
			number++;
		}
		if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
			a[x - mc1][y - mr1] = number;
			space = max(space, calSpace(number));
		}
		y++;
		number++;
		for (int i = 0; i < limit; i++) {
			if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
				a[x - mc1][y - mr1] = number;
				space = max(space, calSpace(number));
			}
			y++;
			number++;
		}
		if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
			a[x - mc1][y - mr1] = number;
			space = max(space, calSpace(number));
		}
		x++;
		number++;
		for (int i = 0; i < limit + 1; i++) {
			if (x <= mc2 && x >= mc1 && y <= mr2 && y >= mr1) {
				a[x - mc1][y - mr1] = number;
				space = max(space, calSpace(number));
			}
			x++;
			number++;
		}
		n++;
	}

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0, k; j <= c2 - c1; j++) {

			k = calSpace(a[j][i]);
			for (int i = 0; i < space - k; i++)
				printf(" ");
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}