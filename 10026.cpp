#include <cstdio>
#include <queue>

using namespace std;

int n;
char a[101][101], b[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> q;
bool visited[101][101];
char c;

void sol(char array[][101]) {
	int t = 0;
	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j])
				continue;
			else {
				q.push({ j,i });
				t++;
				c = array[i][j];
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					if (visited[y][x])
						continue;
					visited[y][x] = true;
					for (int i = 0, px, py; i < 4; i++) {
						px = dx[i] + x;
						py = dy[i] + y;
						if (px<1 || px>n || py<1 || py>n)
							continue;
						if (visited[py][px])
							continue;
						if (array[py][px] == c)
							q.push({ px,py });
					}
				}
			}
		}
	}

	printf("%d ", t);
}

int main() {
	scanf("%d", &n);
	scanf("%c", &c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);
			a[i][j] = c;
			if (c == 'G')
				c = 'R';
			b[i][j] = c;
		}
		scanf("%c", &c);
	}

	sol(a);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			visited[i][j] = false;
	sol(b);

	return 0;
}