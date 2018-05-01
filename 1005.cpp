#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int t, n, m;
int in[1001];
long time[1001];
long total[1001];
vector<int> v[1001];
queue<int> q;

int a, b;
int i;

int main() {

	for (scanf("%d", &t); t--;) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%ld", &time[i]);
			total[i] = time[i];
		}
		for (; m--;) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			in[b]++;
		}

		for (int i = 1; i <= n; i++)
			if (in[i] == 0)
				q.push(i);

		while (!q.empty()) {
			i = q.front();
			q.pop();
			for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); iter++) {
				in[*iter]--;
				total[*iter] = max(total[*iter], total[i] + time[*iter]);
				if (in[*iter] == 0)
					q.push(*iter);
			}
		}
		scanf("%d", &a);
		printf("%ld\n", total[a]);

		for (int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}