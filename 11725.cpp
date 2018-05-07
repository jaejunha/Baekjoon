#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int s[100001];
vector<int> v[100001];
queue<int> q;

int main() {
	int a, b, c;
	scanf("%d", &n);
	s[1] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	q.push(1);
	while (!q.empty()) {
		c = q.front();
		q.pop();
		for (int i = 0, l = v[c].size(); i < l; i++) {
			if (s[c] && s[v[c].at(i)])
				continue;
			else if (s[c])
				s[v[c].at(i)] = c;
			else if (s[v[c].at(i)])
				s[c] = v[c].at(i);

			q.push(v[c].at(i));
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", s[i]);

	return 0;
}