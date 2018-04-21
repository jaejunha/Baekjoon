#include <stdio.h>

int n;
int w[50], h[50];
int r[50];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &h[i]);
		r[i] = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] > w[j] && h[i] > h[j])
				r[j]++;
			else if (w[i] < w[j] && h[i] < h[j])
				r[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", r[i]);

	return 0;
}