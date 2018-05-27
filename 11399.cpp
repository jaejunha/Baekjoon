#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[1001];
int s[1001];
long long t;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	sort(a, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		t += s[i];
	}

	printf("%lld", t);
	return 0;
}