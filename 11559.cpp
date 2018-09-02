#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;
char a[12][6], c;
int t;
vector<P> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			scanf("%c", &a[i][j]);
		scanf("%c", &t);
	}

	t = 0;
	while (true) {
		bool stop = true;
		bool b[12][6];
		int check = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; b[i][j++] = false);
		}
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] == '.')
					continue;
				v.clear();
				c = a[i][j];
				queue<P> q;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (b[x][y])
						continue;
					v.push_back({ x,y });
					b[x][y] = true;
					for (int k = 0; k < 4; k++) {
						int px = x + dx[k];
						int py = y + dy[k];
						if (px < 0 || py < 0 || px >= 12 || py >= 6)
							continue;
						if (b[px][py] || a[px][py] != c)
							continue;
						q.push({ px,py });
					}
				}
				if (v.size() > 3) {
					stop = false;
					for (P p : v)
						a[p.first][p.second] = '.';
				}
				v.clear();
			}
		}

		if (stop)
			break;
		t++;
		for (int i = 0; i < 6; i++) {
			queue<char> q;
			for (int j = 11; j >= 0; j--) {
				if (a[j][i] != '.')
					q.push(a[j][i]);
			}
			int l = q.size();
			for (int j = 11, k = 0; k < l; j--, k++) {
				a[j][i] = q.front();
				q.pop();
			}
			for (int j = 11 - l; j >= 0; j--)
				a[j][i] = '.';
		}
	}
	printf("%d", t);
	return 0;
}