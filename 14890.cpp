#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int a[101][101];
bool b[101][101];
int c;
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}

	int p, q;
	bool e;
	for (int i = 1; i <= n; i++) {
		e = false;
		for (int j = 1; j <= n; j++) {
			if (j == 1)
				p = a[i][j];
			else {
				q = a[i][j] - p;
				if (q >= 2 || q <= -2) {
					e = true;
					break;
				}
				else if (q == -1) {
					if (j + l - 1 > n) {
						e = true;
						break;
					}
					if (j + l <= n) {
						if (a[i][j + l] == p) {
							e = true;
							break;
						}
					}
					p = a[i][j];
					for (int k = 1; k < l; k++) {
						if (p != a[i][j + k] || b[i][j + k]) {
							e = true;
							break;
						}
						else
							b[i][j + k] = true;
					}
					if (e)
						break;
				}
				else if (q == 1) {
					if (j - l < 1) {
						e = true;
						break;
					}
					p = a[i][j];
					if (j - l - 1 > 0) {
						if (a[i][j - l - 1] == p) {
							e = true;
							break;
						}
					}
					for (int k = 1; k <= l; k++) {
						if (p != (a[i][j - k] + 1) || b[i][j - k]) {
							e = true;
							break;
						}
						else
							b[i][j - k] = true;
					}
					if (e)
						break;

				}
				else
					p = a[i][j];
			}
		}
		if (!e)
			c++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			b[i][j] = false;
	}

	for (int i = 1; i <= n; i++) {
		e = false;
		for (int j = 1; j <= n; j++) {
			if (j == 1)
				p = a[j][i];
			else {
				q = a[j][i] - p;
				if (q >= 2 || q <= -2) {
					e = true;
					break;
				}
				else if (q == -1) {
					if (j + l - 1 > n) {
						e = true;
						break;
					}
					if (j + l <= n) {
						if (a[j + l][i] == p) {
							e = true;
							break;
						}
					}
					p = a[j][i];
					for (int k = 1; k < l; k++) {
						if (p != a[j + k][i] || b[j + k][i]) {
							e = true;
							break;
						}
						else
							b[j + k][i] = true;
					}
					if (e)
						break;
				}
				else if (q == 1) {
					if (j - l < 1) {
						e = true;
						break;
					}
					p = a[j][i];
					if (j - l - 1 > 0) {
						if (a[j - l - 1][i] == p) {
							e = true;
							break;
						}
					}
					for (int k = 1; k <= l; k++) {
						if (p != (a[j - k][i] + 1) || b[j - k][i]) {
							e = true;
							break;
						}
						else
							b[j - k][i] = true;
					}
					if (e)
						break;

				}
				else
					p = a[j][i];
			}
		}
		if (!e)
			c++;
	}

	printf("%d", c);
	return 0;
}