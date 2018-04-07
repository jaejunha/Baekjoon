#include <stdio.h>
#include <queue>

using namespace std;

int n, m, v, u;
int g[1001][1001];
int v_q[1001], v_s[1001];
queue<int> q;

void func_queue(int v) {
	int u = v;

	q.push(u);
	v_q[u] = 1;

	while (q.size() > 0) {
		u = q.front();
		q.pop();
		printf("%d ", u);

		for (int i = 1; i <= m; i++) {
			if (g[u][i] && !v_q[i]) {
				q.push(i);
				v_q[i] = 1;
			}
		}
	}
}

void func_stack(int v) {
	v_s[v] = 1;
	printf("%d ", v);

	for (int i = 1; i <= m; i++) {
		if (g[v][i] && !v_s[i])
			func_stack(i);
	}
}

int main() {
	scanf("%d %d %d", &m, &n, &v);

	for (int i = 0, p, q; i < n; i++) {
		scanf("%d %d", &p, &q);
		g[p][q] = 1;
		g[q][p] = 1;
	}

	func_stack(v);
	printf("\n");
	func_queue(v);

	return 0;
}