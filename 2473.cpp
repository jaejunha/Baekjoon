#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
long long a[5000];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	sort(a, a + n);

	int x = 0, y = 1, z = n - 1;
	long long m = a[x] + a[y] + a[z];
	long long t;
	for (int i = 0; i < n - 1; i++) {
		if (m == 0)
			break;
		for (int j = i + 1, k = n - 1; j < k; ) {
			t = a[i] + a[j] + a[k];
			if (abs(t) < abs(m)) {
				m = t;
				x = i;
				y = j;
				z = k;
				if (m < 0)
					j++;
				else
					k--;
			}
			else {
				if (t > 0)
					k--;
				else if (t == 0) {
					m = t;
					x = i;
					y = j;
					z = k;
					break;
				}
				else
					j++;
			}
		}
	}
	printf("%lld %lld %lld", a[x], a[y], a[z]);
	return 0;
}