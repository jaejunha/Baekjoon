#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int a[9];
	int s = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	for (int x = 0; x < 9; x++) {
		for (int y = x + 1; y < 9; y++) {
			if (s - a[x] - a[y] == 100) {
				a[x] = a[y] = 0;
				sort(a, a + 9);
				for (int i = 2; i < 9; i++)
					printf("%d\n", a[i]);
				return 0;
			}
		}
	}
	return 0;
}