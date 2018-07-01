/* reference: http://looview.tistory.com/10 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
typedef pair<int, int> P;
P a[100000];
vector<P> v;
double ans;

double d(P p, P q) {
	return sqrt((p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second));
}

int ccw(P p, P q, P r) {
	return (q.first - p.first)*(r.second - p.second) - (r.first - p.first)*(q.second - p.second);
}

bool comp(P p, P q) {
	long long t = ccw(a[0], p, q);
	if (t > 0)
		return true;
	else if (t < 0)
		return false;
	else
		return d(a[0], p) < d(a[0], q);
}

int main() {
	scanf("%d", &n);
	int o = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
		if (a[o].first > a[i].first)
			o = i;
	}
	swap(a[0], a[o]);
	sort(a + 1, a + n, comp);
	v.push_back(a[0]);
	v.push_back(a[1]);
	for (int i = 2, s; i < n; i++) {
		while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], a[i]) <= 0)
			v.pop_back();
		v.push_back(a[i]);
	}
	for (int i = 0, s = v.size(); i < s - 1; i++) {
		for (int j = i + 1; j < s; j++)
			ans = max(ans, d(v[i], v[j]));
	}

	printf("%.6lf", ans);
	return 0;
}