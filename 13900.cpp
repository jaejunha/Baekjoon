#include <iostream>
using namespace std;

int n;
long long s;
long long t;
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		s += x;
		t += x*x;
	}
	printf("%lld", (s*s - t) / 2);
	return 0;
}