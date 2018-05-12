#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[25][25];
bool b[25][25];
queue<pair<int, int>> q;
vector<int> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &a[i][j]);
	}

	int x, y;
	int c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!b[i][j] && a[i][j]) {
				c = 0;
				q.push({ i, j });
				b[i][j] = true;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					c++;

					q.pop();
					for (int i = 0; i < 4; i++) {
						if (!((x + dx[i] <= n - 1) && (x + dx[i] >= 0)) || !((y + dy[i] <= n - 1) && (y + dy[i] >= 0)))
							continue;
						if (a[x + dx[i]][y + dy[i]] && !b[x + dx[i]][y + dy[i]]) {
							q.push({ x + dx[i],y + dy[i] });
							b[x + dx[i]][y + dy[i]] = true;
						}
					}
				}
				v.push_back(c);
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		printf("%d\n", *i);

	return 0;
}