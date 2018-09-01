/* reference: http://mygumi.tistory.com/195 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int n;
vector<P> v;
bool f;
bool c[9001];
int dst[4002];

void prime() {
	for (int i = 2; i <= 9000; i++)
		c[i] = true;
	for (int i = 2; i <= 94; i++) {
		for (int j = 2 * i; j <= 9000; j += i)
			c[j] = false;
	}
}

int check(int i, int j) {
	return (int)(sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second)));
}

int main() {
	prime();
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d", &n);
	v.resize(n + 2);
	v[0] = { x1, y1 };
	v[n + 1] = { x2,y2 };
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i].first, &v[i].second);

	queue<P> q;
	int s = 9000;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int ix = q.front().first;
		int d = q.front().second;
		q.pop();
		if (ix == n + 1) {
			s = min(s, d);
			f = true;
			continue;
		}
		for (int i = 1, t; i <= n + 1; i++) {
			t = check(ix, i);
			if (!c[t])
				continue;
			if (!dst[i]) {
				dst[i] = d + t;
				q.push({ i, d + t });
			}
			else if (dst[i] > d + t) {
				dst[i] = d + t;
				q.push({ i,d + t });
			}
		}
	}
	if (f)
		printf("%d", s);
	else
		printf("-1");
	return 0;
}