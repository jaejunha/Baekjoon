#include <stdio.h>

int a[101];
int s[10001];

int main() {

	int n, k;
	int mn = 10001;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	s[0] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i - a[j] >= 0) {
				s[i] += s[i - a[j]];
			}
		}
	}

	printf("%d", s[k]);

	return 0;
}