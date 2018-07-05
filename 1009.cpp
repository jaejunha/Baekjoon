#include <cstdio>
using namespace std;

int n, a, b, r;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		r = a % 10;
		int s = 1;
		for (int i = 0; i < b; i++) {
			s *= r;
			s %= 10;
		}
		printf("%d\n", s ? s : 10);
	}
	return 0;
}