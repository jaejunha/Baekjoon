#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool b;
int n, m;
int c;
int a[100];
int s;

void dfs(int x, vector<int> u) {
	if (c == 3) {
		if (u[0] + u[1] + u[2] == m) {
			b = true;
			s = m;
		}
		else if (u[0] + u[1] + u[2] < m)
			s = max(s, u[0] + u[1] + u[2]);
	}
	else {
		for (int i = x + 1; i < n; i++) {
			if (b)
				return;
			c++;
			vector<int> v = u;
			v.push_back(a[i]);
			dfs(i, v);
		}
	}
	c--;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		if (b)
			break;
		c = 1;
		vector<int> v;
		v.push_back(a[i]);
		dfs(i, v);
	}
	printf("%d", s);
	return 0;
}