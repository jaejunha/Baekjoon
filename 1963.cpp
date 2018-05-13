#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool c[10000];
bool b[10000];
queue<pair<int, int>> q;

int main() {
	bool a;
	int n, x, y;
	int t, s, l, m;
	for (int i = 2, j; i <= 100; i++) {
		for (int j = 1000 + (((1000 % i) == 0) ? 0 : (i - 1000 % i)); j < 10000; j += i)
			c[j] = true;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		q.push({ x,0 });
		a = false;
		memset(b, false, 10000);
		b[x] = true;
		m = 999999;
		while (!q.empty()) {
			t = q.front().first;
			l = q.front().second;
			q.pop();

			if (t == y) {
				a = true;
				m = min(m, l);
			}

			for (int i = 1; i <= 9; i++) {
				s = i * 1000 + t % 1000;
				if (!c[s] && !b[s]) {
					q.push({ s,l + 1 });
					b[s] = true;
				}
			}
			for (int i = 0; i <= 9; i++) {
				s = t - (t % 1000) + 100 * i + t % 100;
				if (!c[s] && !b[s]) {
					q.push({ s,l + 1 });
					b[s] = true;
				}
			}
			for (int i = 0; i <= 9; i++) {
				s = t - (t % 100) + 10 * i + t % 10;
				if (!c[s] && !b[s]) {
					q.push({ s,l + 1 });
					b[s] = true;
				}
			}
			for (int i = 1; i <= 9; i += 2) {
				s = t - (t % 10) + i;
				if (!c[s] && !b[s]) {
					q.push({ s,l + 1 });
					b[s] = true;
				}
			}
		}
		if (a)
			printf("%d\n", m);
		else
			printf("Impossible\n");
	}
	return 0;
}