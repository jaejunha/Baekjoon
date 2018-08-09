/* reference: http://donggod.tistory.com/16 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int a[21][21];
int s;
void sol(int x, int b[][21]) {
	if (x == 5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				s = max(s, b[i][j]);
		}
	}
	else {
		int c[21][21];
		queue<int> q;
		for (int i = 1; i <= 4; i++) {
			if (i == 1) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++)
						if (b[k][j])
							q.push(b[k][j]);
					int k = 1;
					while (!q.empty()) {
						int l = q.front();
						q.pop();
						if (!q.empty()) {
							if (l == q.front()) {
								c[k++][j] = 2 * l;
								q.pop();
							}
							else
								c[k++][j] = l;
						}
						else {
							c[k++][j] = l;
							break;
						}
					}
					while (k <= n)
						c[k++][j] = 0;
				}
				sol(x + 1, c);
			}
			else if (i == 2) {
				for (int j = 1; j <= n; j++) {
					for (int k = 1; k <= n; k++)
						if (b[j][k])
							q.push(b[j][k]);
					int k = 1;
					while (!q.empty()) {
						int l = q.front();
						q.pop();
						if (!q.empty()) {
							if (l == q.front()) {
								c[j][k++] = 2 * l;
								q.pop();
							}
							else
								c[j][k++] = l;
						}
						else {
							c[j][k++] = l;
							break;
						}
					}
					while (k <= n)
						c[j][k++] = 0;
				}
				sol(x + 1, c);
			}
			else if (i == 3) {
				for (int j = 1; j <= n; j++) {
					for (int k = n; k >= 1; k--)
						if (b[k][j])
							q.push(b[k][j]);
					int k = n;
					while (!q.empty()) {
						int l = q.front();
						q.pop();
						if (!q.empty()) {
							if (l == q.front()) {
								c[k--][j] = 2 * l;
								q.pop();
							}
							else
								c[k--][j] = l;
						}
						else {
							c[k--][j] = l;
							break;
						}
					}
					while (k >= 1)
						c[k--][j] = 0;
				}
				sol(x + 1, c);
			}
			else {
				for (int j = 1; j <= n; j++) {
					for (int k = n; k >= 1; k--)
						if (b[j][k])
							q.push(b[j][k]);
					int k = n;
					while (!q.empty()) {
						int l = q.front();
						q.pop();
						if (!q.empty()) {
							if (l == q.front()) {
								c[j][k--] = 2 * l;
								q.pop();
							}
							else
								c[j][k--] = l;
						}
						else {
							c[j][k--] = l;
							break;
						}
					}
					while (k >= 0)
						c[j][k--] = 0;
				}
				sol(x + 1, c);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}

	sol(0, a);
	printf("%d", s);
	return 0;
}