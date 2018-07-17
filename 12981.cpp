/* reference: https://github.com/ktjooho/problem_solving/blob/master/12981_%EA%B3%B5%ED%8F%AC%EC%9E%A5%ED%95%98%EA%B8%B0.cpp */
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][101][101];
int sol(int x, int y, int z) {
	int a, b, c;
	a = x < 0 ? 0 : x;
	b = y < 0 ? 0 : y;
	c = z < 0 ? 0 : z;
	if (a == 0 && b == 0 && c == 0)
		return 0;

	int &ret = dp[a][b][c];
	if (ret)
		return ret;
	ret = 100;
	if (a)
		ret = min(ret, sol(a - 3, b, c) + 1);
	if (b)
		ret = min(ret, sol(a, b - 3, c) + 1);
	if (c)
		ret = min(ret, sol(a, b, c - 3) + 1);
	if (a && b)
		ret = min(ret, sol(a - 1, b - 1, c) + 1);
	if (a && c)
		ret = min(ret, sol(a - 1, b, c - 1) + 1);
	if (b && c)
		ret = min(ret, sol(a, b - 1, c - 1) + 1);
	if (a && b && c)
		ret = min(ret, sol(a - 1, b - 1, c - 1) + 1);
	return ret;
}
int r, g, b;
int main() {
	scanf("%d%d%d", &r, &g, &b);
	printf("%d", sol(r, g, b));

	return 0;
}