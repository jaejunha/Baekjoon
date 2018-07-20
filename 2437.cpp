/* reference: http://ksj14.tistory.com/entry/BaekJoon2437-%EC%A0%80%EC%9A%B8 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000000];
long long s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; scanf("%d", &a[i++]));
	sort(a, a + n);
	if (a[0] != 1) {
		printf("1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (s + 1 < a[i])
			break;
		s += a[i];
	}
	printf("%lld", s + 1);

	return 0;
}