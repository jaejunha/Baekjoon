#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, m;
queue<int> q;
bool b[101];
vector<int> v[101];

int main() {
	scanf("%d", &n);

	scanf("%d", &m);
	for (int x, y; m--;) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	q.push(1);
	while (!q.empty()) {
		m = q.front();
		b[m] = true;
		q.pop();

		for (auto it : v[m]) {
			if (b[it])
				continue;
			q.push(it);
		}
	}

	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i])
			c++;
	}
	printf("%d", c - 1);

	return 0;
}