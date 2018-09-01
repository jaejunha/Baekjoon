/* reference: https://www.acmicpc.net/board/view/5411 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k, v, e;
bool b[20001];
int p[20001];
vector<int> u[20001];

void dfs(int x, int c) {
	b[x] = true;
	p[x] = c;
	for (int i : u[x]) {
		if (b[i])
			continue;
		dfs(i, 1 - c);
	}
}

int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &v, &e);
		for (int i = 1; i <= v; i++) {
			b[i] = false;
			p[i] = -1;
			u[i].clear();
		}

		for (int i = 1, x, y; i <= e; i++) {
			scanf("%d%d", &x, &y);
			u[x].push_back(y);
			u[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (b[i])
				continue;
			dfs(i, 0);
		}

		bool f = true;
		for (int i = 1; i <= v; i++) {
			for (int j : u[i]) {
				if (p[i] == p[j]) {
					f = false;
					break;
				}
			}
			if (!f)
				break;
		}
		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}