/* reference: http://www.crocus.co.kr/856 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int t[100001];
void update(int i, int num) {
	while (i <= n) {
		t[i] += num;
		i += (i & -i);
	}
}

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += t[i];
		i -= (i & -i);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i].first);
		v[i].second = i;
		update(i, 1);
	}

	sort(v.begin() + 1, v.end());

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			int l = (i + 1) / 2;
			printf("%d\n", sum(v[l].second) - 1);
			update(v[l].second, -1);
		}
		else {
			int l = n + 1 - i / 2;
			printf("%d\n", sum(n) - sum(v[l].second - 1) - 1);
			update(v[l].second, -1);
		}
	}

	return 0;
}