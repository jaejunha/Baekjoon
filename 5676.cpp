#include <iostream>
using namespace std;
int n, m;
int v[100001];
int z[100001], s[100001];
void update(int *t, int i, int num) {
	while (i <= n) {
		t[i] += num;
		i += (i & -i);
	}
}

int sum(int *t, int i) {
	int ans = 0;
	while (i > 0) {
		ans += t[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		for (int i = 0; i <= n; i++)
			z[i] = s[i] = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			if (!v[i])
				update(z, i, 1);
			else if (v[i] < 0)
				update(s, i, 1);
		}
		char c;
		scanf("%c", &c);
		for (int i = 1, a, b; i <= m; i++) {
			scanf("%c %d %d", &c, &a, &b);
			if (c == 'C') {
				if (!v[a])
					update(z, a, -1);
				else if (v[a] < 0)
					update(s, a, -1);
				v[a] = b;
				if (!v[a])
					update(z, a, 1);
				else if (v[a] < 0)
					update(s, a, 1);
			}
			else {
				if (sum(z, b) - sum(z, a - 1))
					printf("0");
				else {
					int ret = sum(s, b) - sum(s, a - 1);
					if (ret % 2)
						printf("-");
					else
						printf("+");
				}
			}
			scanf("%c", &c);
		}
		printf("\n");
	}
	return 0;
}