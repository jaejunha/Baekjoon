/* reference: http://wookje.dance/2017/11/02/boj-1450-%EB%83%85%EC%83%89%EB%AC%B8%EC%A0%9C/ */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, c, a[30];
vector<int> v[2];
int sol;
void dfs(int s, int x, int t) {
	if (t > c)
		return;
	if (s == 0) {
		if (x > n / 2 - 1) {
			v[s].push_back(t);
			return;
		}
	}
	else {
		if (x > n - 1) {
			v[s].push_back(t);
			return;
		}
	}
	dfs(s, x + 1, t);
	dfs(s, x + 1, t + a[x]);
}
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dfs(0, 0, 0);
	dfs(1, (n / 2), 0);
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	for (int i = 0, j = v[1].size() - 1, l = v[0].size(); i < l; i++) {
		while (j && (v[0][i] + v[1][j] > c))
			j--;
		sol += j + 1;
	}
	printf("%d", sol);
	return 0;
}