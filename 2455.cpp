#include <stdio.h>
#include <algorithm>

using namespace std;

int m, n;
int sum = 0;

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &m, &n);
		sum = max(sum, sum + n - m);
	}
	printf("%d", sum);
	return 0;
}