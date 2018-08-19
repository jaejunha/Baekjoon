/* reference: http://mygumi.tistory.com/232 */
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int n, m;
char a[51][51];
queue<P> q_w, q_m;
int l_w, l_m;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

void water();
bool move() {
	int l_m_t = 0;
	for (int i = 1; i <= l_m; i++) {
		int x = q_m.front().first;
		int y = q_m.front().second;
		q_m.pop();
		for (int j = 0; j < 4; j++) {
			int px = x + dx[j];
			int py = y + dy[j];
			if (px<1 || py<1 || px>n || py>m)
				continue;
			if (a[px][py] == 'D')
				return true;
			if (a[px][py] == '.') {
				a[px][py] = 'S';
				l_m_t++;
				q_m.push({ px,py });
			}
		}
	}
	l_m = l_m_t;
	return false;
}

void water() {
	int l_w_t = 0;

	for (int i = 1; i <= l_w; i++) {
		int x = q_w.front().first;
		int y = q_w.front().second;
		q_w.pop();
		for (int j = 0; j < 4; j++) {
			int px = x + dx[j];
			int py = y + dy[j];
			if (px<1 || py<1 || px>n || py>m)
				continue;
			if (a[px][py] == '.') {
				a[px][py] = '*';
				l_w_t++;
				q_w.push({ px,py });
			}
		}
	}

	l_w = l_w_t;
}

int main() {
	int t;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= m; j++) {
			scanf("%c", &a[i][j]);
			if (a[i][j] == '*')
				q_w.push({ i,j });
			else if (a[i][j] == 'S')
				q_m.push({ i,j });
		}
	}
	t = 0;
	l_w = q_w.size();
	l_m = q_m.size();
	while (1) {
		t++;
		if (!l_m) {
			printf("KAKTUS");
			return 0;
		}
		water();
		if (move()) {
			printf("%d", t);
			return 0;
		}
	}

	return 0;
}