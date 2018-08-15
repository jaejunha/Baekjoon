/* reference: http://stack07142.tistory.com/184 */
#include <iostream>
using namespace std;

int a[51][51];
int n, m, r, c, d;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
bool f;
int sol;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}

	while (1) {
		if (!a[r][c]) {
			a[r][c] = 2;
			sol++;
		}
		f = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			int pr = r + dr[d];
			int pc = c + dc[d];
			if (!a[pr][pc]) {
				r = pr;
				c = pc;
				f = true;
				break;
			}
		}
		if (!f) {
			int pr = r - dr[d];
			int pc = c - dc[d];
			if (a[pr][pc] == 1)
				break;
			else {
				r = pr;
				c = pc;
			}
		}
	}
	printf("%d", sol);
	return 0;
}