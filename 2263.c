#include <stdio.h>

int n;
int a[100001], b[100001];

void print(int il, int ir, int pl, int pr) {
	if (il > ir || pl > pr)
		return;
	printf("%d ", b[pr]);
	int size = a[b[pr]] - il;
	print(il, a[b[pr]] - 1, pl, pl + size - 1);
	size = ir - a[b[pr]];
	print(a[b[pr]] + 1, ir, pr - size, pr - 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, t; i <= n; i++) {
		scanf("%d", &t);
		a[t] = i;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	print(1, n, 1, n);

	return 0;
}