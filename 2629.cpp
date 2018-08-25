/* reference: http://blog.naver.com/PostView.nhn?blogId=bjybaek&logNo=221092492639&redirect=Dlog&widgetTypeCall=true */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, t;
bool b[31][15001];
vector<int> v, u;

void dfs(int x, int s) {
	if (b[x][s])
		return;
	b[x][s] = true;
	if (x <= n - 1) {
		dfs(x + 1, s);
		dfs(x + 1, s + v[x + 1]);
		dfs(x + 1, abs(s - v[x + 1]));
	}
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	dfs(0, 0);
	scanf("%d", &t);
	u.resize(t + 1);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &u[i]);
		if (b[n][u[i]])
			printf("Y ");
		else
			printf("N ");
	}

	return 0;
}