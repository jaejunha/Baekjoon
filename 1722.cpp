#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, l;
long long f = 1, k;
vector<int> v;
int main() {
	scanf("%d%d", &n, &t);
	l = n - 1;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = 2; i <= n - 1; i++)
		f *= i;
	if (t == 1) {
		scanf("%lld", &k);
		if (n > 1) {
			do {
				printf("%d ", v[(int)((k - 1) / f)]);
				v.erase((v.begin() + (int)((k - 1) / f)));
				k %= f;
				if (k == 0)
					k = f;
				f /= l--;
			} while (l > 1);
			if (v.size() > 1)
				printf("%d %d", v[1 - k % 2], v[k % 2]);
			else
				printf("%d", v[0]);
		}
		else
			printf("%d", 1);
	}
	else {
		long long s = 1;
		for (int i = 0, x; i < n - 1; i++) {
			scanf("%d", &x);
			int c = 0;
			for (int j : v) {
				if (x == j)
					break;
				c++;
			}
			v.erase(v.begin() + c);
			s += f * c;
			f /= l--;
		}
		printf("%lld", s);
	}
	return 0;
}