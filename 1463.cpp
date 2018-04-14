#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[1000001];
int main() {

	scanf("%d", &n);
	a[2] = 1;
	a[3] = 1;
	for (int i = 4; i <= n; i++) {
		if ((i % 2 == 0) && (i % 3 != 0))
			a[i] = min(a[i / 2], a[i - 1]) + 1;
		else if ((i % 2 == 1) && (i % 3 == 0))
			a[i] = min(a[i / 3], a[i - 1]) + 1;
		else if ((i % 2 == 0) && (i % 3 == 0))
			a[i] = min(min(a[i / 3], a[i - 1]), a[i / 2]) + 1;
		else
			a[i] = a[i - 1] + 1;
	}
	printf("%d", a[n]);
	return 0;
}