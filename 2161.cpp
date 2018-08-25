#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> q;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		q.push(i);
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();

		if (!q.empty()) {
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
}