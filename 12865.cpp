/* reference: http://huiyu.tistory.com/entry/DP-01-Knapsack%EB%B0%B0%EB%82%AD-%EB%AC%B8%EC%A0%9C */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> v;
int s[101][100001];
int answer;
int main() {
	scanf("%d%d", &n, &k);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);
	sort(v.begin() + 1, v.end());
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (v[i].first <= j)
				s[i][j] = max(v[i].second + s[i - 1][j - v[i].first], s[i - 1][j]);
			else
				s[i][j] = s[i - 1][j];
		}
	}
	printf("%d", s[n][k]);
	return 0;
}