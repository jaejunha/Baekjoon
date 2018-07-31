/* reference: https://github.com/blisstoner/BOJ/blob/master/11387.py */
#include <iostream>
#include <algorithm>
using namespace std;

long long x[4][5];

int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++)
			scanf("%lld", &x[i][j]);
	}

	long long a = x[0][0] * (100 + x[0][1])*(100 * (100 - min(x[0][2], 100LL)) + min(x[0][2], 100LL) * x[0][3])*(100 + x[0][4]);
	long long b = x[1][0] * (100 + x[1][1])*(100 * (100 - min(x[1][2], 100LL)) + min(x[1][2], 100LL) * x[1][3])*(100 + x[1][4]);

	for (int j = 0; j < 5; j++) {
		x[0][j] -= x[2][j];
		x[0][j] += x[3][j];
		x[1][j] -= x[3][j];
		x[1][j] += x[2][j];
	}

	long long c = x[0][0] * (100 + x[0][1])*(100 * (100 - min(x[0][2], 100LL)) + min(x[0][2], 100LL) * x[0][3])*(100 + x[0][4]);
	long long d = x[1][0] * (100 + x[1][1])*(100 * (100 - min(x[1][2], 100LL)) + min(x[1][2], 100LL) * x[1][3])*(100 + x[1][4]);
	if (c - a == 0)
		printf("0\n");
	else if (c > a)
		printf("+\n");
	else
		printf("-\n");

	if (d - b == 0)
		printf("0\n");
	else if (d > b)
		printf("+\n");
	else
		printf("-\n");

	return 0;
}