#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct P {
	int n, g, s, b;
}P;

int n, k;
vector<P> v;
P p;
int r[1001];

bool comp(P pa, P pb) {
	if (pa.g == pb.g) {
		if (pa.s == pb.s) {
			return pa.b > pb.b;
		}
		return pa.s > pb.s;
	}
	return pa.g > pb.g;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &p.n, &p.g, &p.s, &p.b);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), comp);
	int i = 1;
	for (P p : v)
		r[p.n] = i++;
	for (int i = 1; i < n; i++) {
		if ((v[i - 1].g == v[i].g) && (v[i - 1].s == v[i].s) && (v[i - 1].b == v[i].b))
			r[v[i].n] = r[v[i - 1].n];
	}

	printf("%d", r[k]);

	return 0;
}