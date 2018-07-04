/* reference: http://codersbrunch.blogspot.com/2017/08/1708.html */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
typedef pair<int, int> P;
P a[100000];
vector<P> v;
double ans;

long long ccw(P p, P q, P r) {
	return (long long)(q.first - p.first)*(r.second - p.second) - (long long)(r.first - p.first)*(q.second - p.second);
}

bool comp(P p, P q) {
	long long t = ccw(a[0], p, q);
	if (t > 0)
		return true;
	else if (t < 0)
		return false;
	else
		return p < q;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	swap(a[0], *min_element(a, a + n));
	sort(a + 1, a + n, comp);
	v.push_back(a[0]);
	v.push_back(a[1]);
	for (int i = 2, s; i < n; i++) {
		while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], a[i]) <= 0)
			v.pop_back();
		v.push_back(a[i]);
	}
	printf("%d", v.size());
	return 0;
}