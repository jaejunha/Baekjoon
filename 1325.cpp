/* reference: http://2youngjae.tistory.com/13 */
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v[10001];
bool b[10001];
int r[10001];

void dfs(int a) {
	b[a] = true;
	for (auto it : v[a]) {
		if (!b[it]) {
			dfs(it);
			r[it]++;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			b[j] = false;
		dfs(i);
	}

	m = 0;
	for (int i = 1; i <= n; i++)
		m = max(r[i], m);

	for (int i = 1; i <= n; i++) {
		if (r[i] == m)
			printf("%d ", i);
	}
	return 0;
}