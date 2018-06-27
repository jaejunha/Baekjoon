/* reference: http://debuglog.tistory.com/83 */
#include <cstdio>
#include <iostream>
using namespace std;

#define cal(x,y) 3 * (x / 3) + (y / 3)

int a[9][9], cnt;
bool r[9][10], c[9][10], s[9][10], e;

bool check(int x, int y, int n) {
	if (r[x][n])
		return false;
	if (c[y][n])
		return false;
	if (s[cal(x, y)][n])
		return false;

	return true;
}

void dfs() {
	int x = -1, y = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!a[i][j]) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1) {
		e = true;
		return;
	}

	for (int k = 1; k <= 9; k++) {
		if (!r[x][k] && !c[y][k] && !s[cal(x, y)][k]) {
			a[x][y] = k;
			r[x][k] = c[y][k] = s[cal(x, y)][k] = true;
			dfs();
			if (e)
				return;
			a[x][y] = 0;
			r[x][k] = c[y][k] = s[cal(x, y)][k] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);
			if (!a[i][j])
				cnt++;
			else
				r[i][a[i][j]] = c[j][a[i][j]] = s[cal(i, j)][a[i][j]] = true;
		}
	}

	dfs();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; printf("%d ", a[i][j++]));
		printf("\n");
	}
	return 0;
}