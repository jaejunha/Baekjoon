#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, s;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int a;
	for (int i = 0; i <= k; i++) {
		a = min((n - i) / 2, m - (k - i));
		s = max(s, a);
	}
	printf("%d", s);
	return 0;
}