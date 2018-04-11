#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

int main() {

	int a = 0, b = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j > 1; j /= 2) {
			if (j % 2 == 0)
				a++;
			else
				break;
		}
		for (int j = i; j > 4; j /= 5) {
			if (j % 5 == 0)
				b++;
			else
				break;
		}
	}
	printf("%d", min(a, b));
	return 0;
}