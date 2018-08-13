#include <iostream>
using namespace std;

int n, s, c;
int a[20];

void dfs(int x, int p, int b) {
	if (x == n - 1) {
		if (!b)
			return;
		if (p == s)
			c++;
	}
	else {
		dfs(x + 1, p + a[x + 1], b | 1 << (x + 1));
		dfs(x + 1, p, b);
	}
}

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dfs(0, a[0], 1);
	dfs(0, 0, 0);
	printf("%d", c);
	return 0;
}