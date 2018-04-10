#include <stdio.h>

int M[51];
int n, m;
int c;

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &M[i]);
	}

	int p, q;
	while (m > 0) {
		p = M[0] - 1;
		q = n - M[0] + 1;
		if (p > q) {
			c += q;
			for (int i = 0; i < m - 1; i++) {
				M[i] = (M[i + 1] + q - 1 + n) % n;
			}
		}
		else {
			c += p;
			for (int i = 0; i < m; i++) {
				M[i] = (M[i + 1] - p - 1 + n) % n;
			}
		}
		n--;
		m--;
	}
	printf("%d", c);

	return 0;
}