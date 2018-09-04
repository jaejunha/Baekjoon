#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef struct {
	int rx, ry, bx, by, c;
}B;
int n, m, t;
char a[11][11];

int main() {
	scanf("%d%d", &n, &m);
	B b;
	for (int i = 0; i < n; i++) {
		scanf("%c", &t);
		for (int j = 0; j < m; j++) {
			scanf("%c", &a[i][j]);
			if (a[i][j] == 'R') {
				b.rx = i;
				b.ry = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'B') {
				b.bx = i;
				b.by = j;
				a[i][j] = '.';
			}
		}
	}
	b.c = 0;
	queue<B> q;
	q.push(b);
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int c = q.front().c;
		q.pop();
		if (c == 10) {
			printf("-1");
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			bool e = false;
			bool f = false;
			int prx = rx;
			int pry = ry;
			int pbx = bx;
			int pby = by;
			// case 1:
			if (i == 0) {
				if (prx < pbx) {
					while (prx > 0) {
						if (a[prx - 1][pry] == 'O')
							f = true;
						else if (a[prx - 1][pry] == '#')
							break;
						else if (pbx == prx - 1 && pby == pry)
							break;
						prx--;
					}
					while (pbx > 0) {
						if (a[pbx - 1][pby] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx - 1][pby] == '#')
							break;
						else if (pbx - 1 == prx && pby == pry)
							break;
						pbx--;
					}
					if (e)
						continue;
					if (f) {
						printf("%d", c + 1);
						return 0;
					}
				}
				else {
					while (pbx > 0) {
						if (a[pbx - 1][pby] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx - 1][pby] == '#')
							break;
						else if (pbx - 1 == prx&& pby == pry)
							break;
						pbx--;
					}
					if (e)
						continue;
					while (prx > 0) {
						if (a[prx - 1][pry] == 'O') {
							printf("%d", c + 1);
							return 0;
						}
						else if (a[prx - 1][pry] == '#')
							break;
						else if (pbx == prx - 1 && pby == pry)
							break;
						prx--;
					}
				}
			}
			// case 2:
			else if (i == 1) {
				if (prx > pbx) {
					while (prx < n - 1) {
						if (a[prx + 1][pry] == 'O')
							f = true;
						else if (a[prx + 1][pry] == '#')
							break;
						else if (pbx == prx + 1 && pby == pry)
							break;
						prx++;
					}
					while (pbx < n - 1) {
						if (a[pbx + 1][pby] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx + 1][pby] == '#')
							break;
						else if (pbx + 1 == prx && pby == pry)
							break;
						pbx++;
					}
					if (e)
						continue;
					if (f) {
						printf("%d", c + 1);
						return 0;
					}
				}
				else {
					while (pbx < n - 1) {
						if (a[pbx + 1][pby] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx + 1][pby] == '#')
							break;
						else if (pbx + 1 == prx && pby == pry)
							break;
						pbx++;
					}
					if (e)
						continue;
					while (prx < n - 1) {
						if (a[prx + 1][pry] == 'O') {
							printf("%d", c + 1);
							return 0;
						}
						else if (a[prx + 1][pry] == '#')
							break;
						else if (pbx == prx + 1 && pby == pry)
							break;
						prx++;
					}
				}
			}
			// case 3:
			else if (i == 2) {
				if (pry < pby) {
					while (pry > 0) {
						if (a[prx][pry - 1] == 'O')
							f = true;
						else if (a[prx][pry - 1] == '#')
							break;
						else if (pbx == prx && pby == pry - 1)
							break;
						pry--;
					}
					while (pby > 0) {
						if (a[pbx][pby - 1] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx][pby - 1] == '#')
							break;
						else if (pbx == prx && pby - 1 == pry)
							break;
						pby--;
					}
					if (e)
						continue;
					if (f) {
						printf("%d", c + 1);
						return 0;
					}
				}
				else {
					while (pby > 0) {
						if (a[pbx][pby - 1] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx][pby - 1] == '#')
							break;
						else if (pbx == prx && pby - 1 == pry)
							break;
						pby--;
					}
					if (e)
						continue;
					while (pry > 0) {
						if (a[prx][pry - 1] == 'O') {
							printf("%d", c + 1);
							return 0;
						}
						else if (a[prx][pry - 1] == '#')
							break;
						else if (pbx == prx && pby == pry - 1)
							break;
						pry--;
					}
				}
			}
			// case 4:
			else {
				if (pry > pby) {
					while (pry < m - 1) {
						if (a[prx][pry + 1] == 'O')
							f = true;
						else if (a[prx][pry + 1] == '#')
							break;
						else if (pbx == prx && pby == pry + 1)
							break;
						pry++;
					}
					while (pby < m - 1) {
						if (a[pbx][pby + 1] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx][pby + 1] == '#')
							break;
						else if (pbx == prx && pby + 1 == pry)
							break;
						pby++;
					}
					if (e)
						continue;
					if (f) {
						printf("%d", c + 1);
						return 0;
					}
				}
				else {
					while (pby < m - 1) {
						if (a[pbx][pby + 1] == 'O') {
							e = true;
							break;
						}
						else if (a[pbx][pby + 1] == '#')
							break;
						else if (pbx == prx && pby + 1 == pry)
							break;
						pby++;
					}
					if (e)
						continue;
					while (pry < m - 1) {
						if (a[prx][pry + 1] == 'O') {
							printf("%d", c + 1);
							return 0;
						}
						else if (a[prx][pry + 1] == '#')
							break;
						else if (pbx == prx && pby == pry + 1)
							break;
						pry++;
					}
				}
			}
			if (rx == prx && ry == pry && bx == pbx && by == pby)
				continue;
			b.rx = prx;
			b.ry = pry;
			b.bx = pbx;
			b.by = pby;
			b.c = c + 1;
			q.push(b);
		}
	}
	printf("-1");
	return 0;
}