#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int b[1001];
int c;

int main() {

	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		b[i] = 10000;
		int j = lower_bound(b, b + i, a[i]) - b;
		if (b[j] == 10000)
			c++;
		b[j] = a[i];
	}
	printf("%d", c);

	return 0;
}