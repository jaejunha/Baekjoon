#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[10001];
int s[10001];
int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	s[1] = a[1];
	s[2] = a[1] + a[2];
	s[3] = max(a[3] + max(a[1], a[2]), s[2]);

	for (int i = 4; i <= n; i++)
		s[i] = max(a[i] + max(s[i - 2], a[i - 1] + s[i - 3]), s[i - 1]);

	printf("%d", max(s[n], s[n - 1]));
	return 0;
}