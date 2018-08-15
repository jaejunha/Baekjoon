#include <iostream>
#include <cstring>
using namespace std;

int n, l, k, v[1000];
char a[200];
bool b[100], e;

void dfs(int x, int y) {
	if (x == n) {
		if (y != l)
			return;
		for (int i = 1; i <= l; i++) {
			if (!b[i])
				return;
		}

		for (int i = 0; i < l; i++)
			printf("%d ", v[i]);
		e = true;
	}
	else if (x + 1 <= n) {
		if (e || a[x] == '0')
			return;
		int i = a[x] - '0', j;
		if (l >= 10) {
			if (i <= k) {
				j = a[x + 1] - '0';
				if (x + 2 <= n) {
					v[y] = i * 10 + j;
					if (!b[v[y]]) {
						b[v[y]] = true;
						dfs(x + 2, y + 1);
						b[v[y]] = false;
						if (e)
							return;
					}
				}
				v[y] = i;
				if (!b[v[y]]) {
					b[v[y]] = true;
					dfs(x + 1, y + 1);
					b[v[y]] = false;
					if (e)
						return;
				}
			}
			else {
				v[y] = i;
				if (!b[v[y]]) {
					b[v[y]] = true;
					dfs(x + 1, y + 1);
					b[v[y]] = false;
					if (e)
						return;
				}
			}
		}
		else {
			v[y] = i;
			if (!b[v[y]]) {
				b[v[y]] = true;
				dfs(x + 1, y + 1);
				b[v[y]] = false;
				if (e)
					return;
			}
		}
	}
}

int main() {
	scanf("%s", a);
	n = strlen(a);
	if (n <= 9) {
		for (char c : a)
			printf("%c ", c);
	}
	else {
		l = 9 + (n - 9) / 2;
		k = l / 10;
		int i = v[0] = a[0] - '0';
		if (l >= 10) {
			if (v[0] <= k) {
				if (2 <= n) {
					v[0] = v[0] * 10 + (a[1] - '0');
					if (!b[v[0]]) {
						b[v[0]] = true;
						dfs(2, 1);
						b[v[0]] = false;
						v[0] = i;
					}
				}
				if (!b[v[0]]) {
					b[v[0]] = true;
					dfs(1, 1);
					b[v[0]] = false;
				}
			}
			else {
				if (!b[v[0]]) {
					b[v[0]] = true;
					dfs(1, 1);
					b[v[0]] = false;
				}
			}
		}
		else {
			if (!b[v[0]]) {
				b[v[0]] = true;
				dfs(1, 1);
				b[v[0]] = false;
			}
		}
	}
	return 0;
}