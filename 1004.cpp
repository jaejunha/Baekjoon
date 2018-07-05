#include <iostream>
#include <cmath>
using namespace std;

int t;
int n;
int x, y, r;
int ans;
pair<int, int> s, f;
int check(pair<int, int> p, int x, int y, int r) {
	if (sqrt((p.first - x)*(p.first - x) + (p.second - y)*(p.second - y)) < r)
		return -1;
	else
		return 1;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &s.first, &s.second, &f.first, &f.second);
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &x, &y, &r);
			if (check(s, x, y, r)*check(f, x, y, r) == -1)
				ans++;
		}
		printf("%d\n", ans);
	}
}