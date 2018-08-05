#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, s = 100000;
int dp[100001];

int dfs(int m) {
	if (m == 1)
		return 1;
	if (m == 0)
		return 0;
	int &ret = dp[m];
	if (ret)
		return ret;
	ret = 100001;
	for (int i = sqrt(m); i >= 1; i--)
		ret = min(ret, dfs(m - i*i) + 1);
	return ret;
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	for (int i = sqrt(n); i >= 1; i--) {
		s = min(s, dfs(n - i*i) + 1);
	}
	printf("%d", s);
	return 0;
}