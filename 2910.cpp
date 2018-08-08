#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct P {
	int first, second, third;
};

bool b;
vector<P> v;
int n, c;
int a[1001];

bool comp(P p, P q) {
	if (p.second == q.second)
		return p.third < q.third;
	return p.second > q.second;
}

int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b = false;
		for (int j = 0, l = v.size(); j < l; j++) {
			if (v[j].first == a[i]) {
				b = true;
				v[j].second++;
				break;
			}
		}
		if (!b)
			v.push_back({ a[i], 1 , i });
	}
	sort(v.begin(), v.end(), comp);

	for (P p : v) {
		for (int i = 0; i < p.second; i++)
			printf("%d ", p.first);
	}
	return 0;
}