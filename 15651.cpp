#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
void dfs(int x, vector<int> v) {
	if (x == m) {
		for (int i : v)
			printf("%d ", i);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		vector<int> u = v;
		u.push_back(i);
		dfs(x + 1, u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	vector<int> v;
	dfs(0, v);
	return 0;
}