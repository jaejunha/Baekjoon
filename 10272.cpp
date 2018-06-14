#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> v;
int n, t;
double dp[513][513];

double d(pair<int, int> p, pair<int, int> q) {
	return sqrt((p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second));
}

double sol(int i, int j) {
	if (j == n) {
		if (i != n)
			return d(v.at(i), v.at(j));
		return 0.0;
	}
	if (i == n) {
		if (j != n)
			return d(v.at(i), v.at(j));
		return 0.0;
	}

	double &ret = dp[i][j];
	if (ret != -1.0)
		return ret;
	ret = 999999.0;
	int m = max(i, j) + 1;
	ret = min(ret, sol(m, j) + d(v.at(m), v.at(i)));
	ret = min(ret, sol(i, m) + d(v.at(m), v.at(j)));

	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.resize(n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = -1.0;
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &v.at(i).first, &v.at(i).second);
		printf("%lf\n", sol(1, 1));

		if (t) {
			v.clear();
		}
	}
	return 0;
}