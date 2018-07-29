#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> L;

int n, ans;
vector<L> v;

int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &v[i].first, &v[i].second);

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				long long a = (v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second);
				long long b = (v[i].first - v[k].first)*(v[i].first - v[k].first) + (v[i].second - v[k].second)*(v[i].second - v[k].second);
				long long c = (v[k].first - v[j].first)*(v[k].first - v[j].first) + (v[k].second - v[j].second)*(v[k].second - v[j].second);
				if (a > b) {
					if (a > c) {
						if (a == b + c)
							ans++;
					}
					else {
						if (c == a + b)
							ans++;
					}
				}
				else {
					if (b > c) {
						if (b == a + c)
							ans++;
					}
					else {
						if (c == a + b)
							ans++;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}