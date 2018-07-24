#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100], ret, mx = -1000000000, mn = 1000000000, o[100];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 1, j = 0, x; i <= 4; i++) {
		scanf("%d", &x);
		for (int k = 0; k < x; k++)
			o[j++] = i;
	}

	do {
		ret = a[0];
		for (int i = 0; i < n - 1; i++) {
			if (o[i] == 1)
				ret += a[i + 1];
			else if (o[i] == 2)
				ret -= a[i + 1];
			else if (o[i] == 3)
				ret *= a[i + 1];
			else
				ret /= a[i + 1];
		}
		mx = max(mx, ret);
		mn = min(mn, ret);
	} while (next_permutation(o, o + n - 1));

	printf("%d\n%d", mx, mn);
	return 0;
}