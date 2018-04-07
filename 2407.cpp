#include <stdio.h>
#include <algorithm>

#define UNIT 1000

using namespace std;

int n, k;
int s[UNIT];
int r = 0;
int main() {
	scanf("%d %d", &n, &k);

	k = min(k, n - k);

	s[0] = 1;

	for (int i = 0, carry; i < k; i++) {
		carry = 0;
		for (int j = 0; j < UNIT; j++) {
			s[j] *= n;
			s[j] += carry;
			carry = s[j] / UNIT;
			s[j] %= UNIT;
			if (!s[j + 1] && carry == 0) {
				if (j + 1 > r) {
					r = j + 1;
					break;
				}
			}
		}
		n--;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = r, t; j >= 0; j--) {
			t = s[j] % i;
			s[j] /= i;
			if (j>0)
				s[j - 1] += t * UNIT;
		}
		if (!s[r])
			r--;
	}

	printf("%d", s[r]);
	for (int i = r - 1; i >= 0; i--) {
		printf("%03d", s[i]);
	}

	return 0;
}