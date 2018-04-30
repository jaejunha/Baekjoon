#include <stdio.h>
#include <queue>
#include <set>

using namespace std;

int n;
int in[501];
int time[501];
int total[501];
set<int> s[501];
queue<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 1, a, j; i <= n; i++) {
		j = 1;
		while (true) {
			scanf("%d", &a);
			if (a == -1)
				break;
			if (j == 1)
				time[i] = a;
			else {
				s[a].insert(i);
				in[i]++;
			}
			j++;
		}
	}

	for (int i = 1; i <= n; i++) {
		total[i] = time[i];
		if (in[i] == 0)
			q.push(i);
	}

	int index;
	while (!q.empty()) {
		index = q.front();
		q.pop();

		for (set<int>::iterator iter = s[index].begin(); iter != s[index].end(); iter++) {
			in[*iter]--;
			total[*iter] = max(total[*iter], total[index] + time[*iter]);
			if (in[*iter] == 0) {
				q.push(*iter);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", total[i]);

	return 0;
}