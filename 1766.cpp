#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m;
int in[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int a, b;
int i;

int main() {

	scanf("%d", &n);
	for (scanf("%d", &m); m--;) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i <= n; i++)
		if (in[i] == 0)
			pq.push(i);

	while (!pq.empty()) {
		i = pq.top();
		printf("%d ", i);
		pq.pop();
		for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++) {
			in[*iter]--;
			if (in[*iter] == 0)
				pq.push(*iter);
		}
	}
	return 0;
}