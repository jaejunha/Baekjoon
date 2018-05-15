#include <stdio.h>
#include <math.h>
#include <stack>

using namespace std;

int a[32768];
stack<int> s;

int main() {
	int n;
	scanf("%d", &n);
	int p = pow(2, n - 1);
	int l = 2 * p;
	a[1] = 1;
	for (int i = 2, s = 1; i <= n; i++, s *= 2) {
		for (int j = s, k = 2 * s; j < k; j++) {
			a[2 * j] = a[j] + s;
			a[2 * j + 1] = a[2 * j] + s;
		}
	}
	for (int i = p, k = p / 2, j = 1, t; j <= k; i++, j++) {
		t = a[i];
		a[i] = a[l - j];
		a[l - j] = t;
	}

	s.push(1);
	int t;
	while (!s.empty()) {
		t = s.top();
		s.pop();
		printf("%d ", a[t]);
		if (2 * t < l)
			s.push(2 * t);
		if (2 * t + 1 < l)
			s.push(2 * t + 1);
	}


	return 0;
}