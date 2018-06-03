#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v, s;

bool comp(pair<int, int> p, pair<int, int> q) {
	if (p.second == q.second)
		return p.first < q.first;

	return p.second < q.second;
}

int main() {

	scanf("%d", &n);
	for (int i = 1, a, b; i <= n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), comp);

	s.push_back(v.at(0));
	for (int i = 1; i < n; i++) {
		if (v.at(i).first >= s.back().second) {
			s.push_back(v.at(i));
		}
	}

	printf("%d", s.size());

	return 0;
}