#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int sum;

int comb(int n, int k) {
	int m = min(k, n - k);
	long s = 1;
	for (int i = 0; i < m; i++) {
		s *= (n - i);
		s /= (i + 1);
	}
	return s;
}

int main() {

	int flag = 0;
	int c;
	int t;

	scanf("%d", &n);

	if (n < 10) {
		printf("%d", n);
		return 0;
	}
	else if (n == 1022) {
		printf("9876543210");
		return 0;
	}
	sum += 9;

	for (int i = 2; i <= 9; i++) {
		for (int j = i - 1, k; j <= 9; j++) {
			k = comb(j, i - 1);
			if (sum + k >= n) {
				flag = 1;
				c = i;
				t = j;
				printf("%d", j);
				break;
			}
			sum += k;
		}
		if (flag)
			break;
	}

	if (!flag) {
		printf("-1");
		return 0;
	}

	for (int i = c - 1; i >= 1; i--) {
		flag = 0;
		for (int j = i - 1, k; j <= 9; j++) {
			k = comb(j, i - 1);
			if (sum + k >= n) {
				flag = 1;
				printf("%d", j);
				t = j;
				break;
			}
			if (flag)
				break;

			sum += k;
		}
	}

	return 0;
}