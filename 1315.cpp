/* reference: https://lyzqm.blogspot.com/2017/08/1315-rpg.html */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Q {
	int s, i, p;
};

int n;
vector<Q> v;
bool b[101];
int dp[1001][1001];

int sol(int x, int y) {
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	vector<int> u;
	int s = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].s <= x || v[i].i <= y) {
			if (!b[i]) {
				b[i] = true;
				u.push_back(i);
				s += v[i].p;
			}
			c++;
		}
	}
	ret = c;
	for (int i = x, l = min(1000, x + s), j; i <= l; i++) {
		j = min(1000, y + s - (i - x));
		ret = max(ret, sol(i, j));
	}
	for (int i : u)
		b[i] = false;
	return ret;
}

int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++)
			dp[i][j] = -1;
	}
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &v[i].s, &v[i].i, &v[i].p);
	printf("%d", sol(1, 1));
	return 0;
}