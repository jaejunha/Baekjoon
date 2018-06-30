#include <cstdio>
using namespace std;
int a, b, c, n;
int t[401] = { 0, };
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &n);
	t[0] = 1;
	for (int i = 0; i <= n; i++) {
		if (t[i]) {
			t[i + a] = 1;
			t[i + b] = 1;
			t[i + c] = 1;
		}
	}
	printf("%d", t[n]);
	return 0;
}