#include <stdio.h>

using namespace std;

int n;
int s = 1;
int main() {
	scanf("%d", &n);

	for (int i = 0, j = n; i < n; i++, j--) {
		s *= j;
	}
	printf("%d", s);

	return 0;
}