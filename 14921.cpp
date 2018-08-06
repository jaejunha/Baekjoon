#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, a[100001], s = 200000000;

bool comp(int x, int y) { return abs(x) < abs(y); }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, comp);
	for (int i = 0, x; i < n - 1; i++) {
		x = a[i] + a[i + 1];
		if (abs(s) > abs(x))
			s = x;
	}
	printf("%d", s);
	return 0;
}