/* reference: http://jason9319.tistory.com/224 */
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int w, n;
vector<pair<int, int>> v;
int level;
int x, y;
int dp[1001][1001];
int trace[1001];

int cal(pair<int, int> p, pair<int, int> q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

int sum(int x, int y) {
	if (x == w || y == w)
		return 0;
	int &ret = dp[x][y];
	if (ret != -1)return ret;
	int a, b;
	int m = max(x, y);
	if (x == 0)
		a = sum(m + 1, y) + cal(v.at(m + 1), { 1,1 });
	else
		a = sum(m + 1, y) + cal(v.at(m + 1), v.at(x));
	if (y == 0)
		b = sum(x, m + 1) + cal(v.at(m + 1), { n,n });
	else
		b = sum(x, m + 1) + cal(v.at(m + 1), v.at(y));
	return ret = min(a, b);
}

void sub(int x, int y) {
	if (x == w || y == w)
		return;
	int a, b;
	int m = max(x, y);
	if (x == 0)
		a = sum(m + 1, y) + cal(v.at(m + 1), { 1,1 });
	else
		a = sum(m + 1, y) + cal(v.at(m + 1), v.at(x));
	if (y == 0)
		b = sum(x, m + 1) + cal(v.at(m + 1), { n,n });
	else
		b = sum(x, m + 1) + cal(v.at(m + 1), v.at(y));
	if (a < b) {
		trace[m + 1] = 1;
		sub(m + 1, y);
	}
	else {
		trace[m + 1] = 2;
		sub(x, m + 1);
	}
}

int main() {
	scanf("%d%d", &n, &w);
	v.resize(w + 1);
	for (int i = 0; i <= w; i++) {
		if (i != 0)
			scanf("%d%d", &v.at(i).first, &v.at(i).second);
		for (int j = 0; j <= w; j++)
			dp[i][j] = -1;
	}
	printf("%d\n", sum(0, 0));
	sub(0, 0);
	for (int i = 1; i <= w; i++)
		printf("%d\n", trace[i]);
	return 0;
}

