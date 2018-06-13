/* reference: https://fatc.club/2017/03/01/376 */
#include <cstdio>
using namespace std;

double a, b;
bool p[19];
double dp[19][19][19];

double sol(int n, int x, int y) {
	if (n == 18) return ((p[x] || p[y]) ? 1.0 : 0.0);
	double &ret = dp[n][x][y];
	if (ret != -1.0)
		return ret;
	ret = 0.0;
	ret += sol(n + 1, x, y)*(1.0 - a)*(1.0 - b);
	ret += sol(n + 1, x + 1, y)*a*(1.0 - b);
	ret += sol(n + 1, x, y + 1)*(1.0 - a)*b;
	ret += sol(n + 1, x + 1, y + 1)*a*b;

	return ret;
}

int main() {
	p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = true;

	scanf("%lf%lf", &a, &b);
	a /= 100;
	b /= 100;
	for (int i = 0; i <= 18; i++)
		for (int j = 0; j <= 18; j++)
			for (int k = 0; k <= 18; k++)
				dp[i][j][k] = -1.0;

	printf("%0.16lf", sol(0, 0, 0));
	return 0;
}
