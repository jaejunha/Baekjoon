/* reference: http://barefoot-coder.tistory.com/35 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
int t, n;
vector<P> v;
bool b[101];

void dfs(int x, int y) {
	for (int i = 1; i <= n + 1; i++) {
		if (b[i])
			continue;

		if (abs(x - v[i].first) + abs(y - v[i].second) <= 1000) {
			b[i] = true;
			dfs(v[i].first, v[i].second);
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.resize(n + 2);
		for (int i = 0; i <= n + 1; i++)
			scanf("%d%d", &v[i].first, &v[i].second);

		for (int i = 1; i <= n + 1; b[i++] = false);
		for (int i = 1; i <= n + 1; i++) {
			if (abs(v[0].first - v[i].first) + abs(v[0].second - v[i].second) <= 1000) {
				b[i] = true;
				dfs(v[i].first, v[i].second);
			}
		}
		if (b[n + 1])
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}