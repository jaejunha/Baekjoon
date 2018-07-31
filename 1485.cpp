#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, x, y;
vector<pair<int, int>> v;
long long a[6];

long long cal(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		v.clear();
		for (int i = 0; i < 4; i++) {
			scanf("%d %d", &x, &y);
			v.push_back({ x, y });
		}
		a[0] = cal(v[0], v[1]);
		a[1] = cal(v[1], v[2]);
		a[2] = cal(v[2], v[3]);
		a[3] = cal(v[3], v[0]);
		a[4] = cal(v[0], v[2]);
		a[5] = cal(v[1], v[3]);
		sort(a, a + 6);
		if ((a[0] == a[3]) && (a[4] == a[5]))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}