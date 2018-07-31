/* reference: http://baactree.tistory.com/6 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, m, l;
int a[100001], tree[200003];

void update(int i, int num) {
	while (i < l) {
		tree[i] += num;
		i += i&(-i);
	}
}

int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= i&(-i);
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(tree, 0, sizeof(tree));
		memset(a, 0, sizeof(a));
		l = n + m + 1;
		for (int i = 1; i <= n; i++) {
			a[i] = i + m;
			update(a[i], 1);
		}
		for (int i = 0, x; i < m; i++) {
			scanf("%d", &x);
			printf("%d ", sum(a[x]) - 1);
			update(a[x], -1);
			a[x] = m - i;
			update(a[x], 1);
		}
		printf("\n");
	}
	return 0;
}