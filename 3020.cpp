/* reference: http://ksj14.tistory.com/entry/BaekJoon3020-%EA%B0%9C%EB%98%A5%EB%B2%8C%EB%A0%88 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h, a[100000], b[100000], c[500001];

int d(int y) {
	int s = 0, f = m - 1, ans;
	int mid;
	while (s <= f) {
		mid = (s + f) / 2;
		if (a[mid] < y)
			s = mid + 1;
		else {
			ans = mid;
			f = mid - 1;
		}
	}
	return m - f - 1;
}

int u(int y) {
	int s = 0, f = m - 1, ans;
	int mid;
	while (s <= f) {
		mid = (s + f) / 2;
		if (b[mid] < h - y + 1)
			s = mid + 1;
		else {
			ans = mid;
			f = mid - 1;
		}
	}
	return m - f - 1;

}

int main() {
	scanf("%d%d", &n, &h);
	for (int i = 0; i < n; i++) {
		if (i % 2)
			scanf("%d", &b[i / 2]);
		else
			scanf("%d", &a[i / 2]);
	}
	m = n / 2;
	sort(a, a + m);
	sort(b, b + m);
	for (int i = 1; i <= h; i++)
		c[i] = d(i) + u(i);
	sort(c + 1, c + h + 1);
	int t = 0;
	for (int i = 1; i <= h; i++) {
		if (c[i] == c[1])
			t++;
		else
			break;
	}
	printf("%d\n%d\n", c[1], t);
	return 0;
}