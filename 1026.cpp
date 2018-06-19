#include <cstdio>
#include <algorithm>

using namespace std;

bool com(int x, int y) {
	return x > y;
}

int n;
int s;
int a[51], b[51];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	sort(a, a + n, com);
	sort(b, b + n);

	for (int i = 0; i < n; i++)
		s += a[i] * b[i];
	printf("%d", s);

	return 0;
}