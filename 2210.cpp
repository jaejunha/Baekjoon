#include <iostream>
#include <set>
using namespace std;

int a[6][6];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
set<int> s;

void dfs(int x, int y, int n, int t) {
	if (t == 6) {
		s.insert(n);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];
		if (px < 1 || py < 1 || px>5 || py>5)
			continue;
		dfs(px, py, 10 * n + a[px][py], t + 1);
	}
}

int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++)
			dfs(i, j, a[i][j], 1);
	}

	cout << s.size();
	return 0;
}