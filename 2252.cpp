#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int in[32001];
vector<int> v[32001];
queue<int> q;

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
			q.push(i);

	while (!q.empty()) {
		i = q.front();
		printf("%d ", i);
		q.pop();
		for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++) {
			in[*iter]--;
			if (in[*iter] == 0)
				q.push(*iter);
		}
	}
	return 0;
}