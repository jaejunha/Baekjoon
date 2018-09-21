#include <stdio.h>

short seive[1000];

void check(int i) {
	if (i >= 100) {
		int d = (i / 100) - (i % 100 / 10);
		if (d != ((i % 100 / 10) - (i % 10))) seive[i - 1] = 1;
	}
}

int main() {
	int n, counter = 0;
	while (!(scanf("%d", &n) && (n >= 1 && n <= 1000)));
	for (int i = 1; i <= n; i++)
		check(i);
	for (int i = 0; i<n; i++)
		if (!seive[i]) counter++;
	printf("%d", counter);
	return 0;
}