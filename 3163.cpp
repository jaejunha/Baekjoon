#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int t;
int L, N, K;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
deque<int> i;

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d %d %d", &N, &L, &K);
		a.clear();
		b.clear();
		i.clear();
		for (int j = 0, k, l; j < N; j++) {
			scanf("%d %d", &k, &l);
			a.push_back(pair<int, int>(l>0 ? L - k : k, l));
			i.push_back(l);
		}
		sort(a.begin(), a.end());
		for (int j = 0; j < N; j++) {
			if (a[j].second < 0) {
				b.push_back(pair<int, int>(a[j].first, i.front()));
				i.pop_front();
			}
			else {
				b.push_back(pair<int, int>(a[j].first, i.back()));
				i.pop_back();
			}
		}
		sort(b.begin(), b.end());
		printf("%d\n", b[K - 1].second);
	}

	return 0;
}