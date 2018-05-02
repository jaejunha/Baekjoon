#include <stdio.h>

int n, m;
int p[1000002];

int find(int n) {
	if (p[n] == n)
		return n;
	else
		return (p[n] = find(p[n]));
}

int main() {
	int o, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		p[i] = i;
	while (m--) {
		scanf("%d %d %d", &o, &a, &b);
		if (o) {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			p[find(a)] = find(b);
	}
	return 0;
}