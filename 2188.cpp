/* reference: http://www.crocus.co.kr/498 */
#include <cstdio>

using namespace std;

int n, m;
bool a[201][201];
int a_n[201], a_m[201];
int sol;
bool b[201];

bool dfs(int x) {
	if (b[x])
		return false;
	b[x] = true;
	for (int i = 1; i <= m; i++) {
		if (a[x][i]) {
			if (a_m[i] == 0 || dfs(a_m[i])) {
				a_n[x] = i;
				a_m[i] = x;

				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 1; j <= x; j++) {
			scanf("%d", &y);
			a[i][y] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			b[j] = false;
		if (dfs(i))
			sol++;
	}
	printf("%d", sol);

	return 0;
}