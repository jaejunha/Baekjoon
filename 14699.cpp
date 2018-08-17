#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, s;
int h[5001];
vector<int> v[5001];
bool r[5001][5001];
int dp[5001];

int dfs(int x) {
	int &ret = dp[x];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i : v[x]) {
		if (h[i] > h[x])
			ret = max(ret, dfs(i) + 1);
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	int a, b;
	while (m--) {
		scanf("%d%d", &a, &b);
		if (h[a] == h[b])
			continue;
		else if (h[a] > h[b]) {
			if (!r[b][a]) {
				v[b].push_back(a);
				r[b][a] = true;
			}
		}
		else {
			if (!r[a][b]) {
				v[a].push_back(b);
				r[a][b] = true;
			}
		}
	}
	for (int i = 0; i < 5001; i++)
		dp[i] = -1;
	for (int i = 1; i <= n; i++)
		printf("%d\n", dfs(i));

	return 0;
}