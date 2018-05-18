#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int f, s;
int t = 1000000;
bool v[100001];
queue<pair<int, int>> q;

int main() {
	scanf("%d %d", &n, &k);
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		f = q.front().first;
		s = q.front().second;
		q.pop();
		s++;

		if (f == k)
			t = min(t, s);
		else {
			if (f < 0 || f > 100000)
				continue;
			if (v[f])
				continue;
			v[f] = true;
			if (f > k)
				q.push(make_pair(f - 1, s));
			else {
				q.push(make_pair(f - 1, s));
				q.push(make_pair(f + 1, s));
				q.push(make_pair(2 * f, s));
			}
		}
	}
	printf("%d", t - 1);

	return 0;
}