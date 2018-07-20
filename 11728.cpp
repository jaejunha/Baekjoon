#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[1000000], b[1000000];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; scanf("%d", &a[i++]));
	for (int i = 0; i < m; scanf("%d", &b[i++]));
	int i = 0;
	int j = 0;
	while (i != n && j != m) {
		if (a[i] < b[j])
			printf("%d ", a[i++]);
		else
			printf("%d ", b[j++]);
	}
	while (i != n)
		printf("%d ", a[i++]);
	while (j != m)
		printf("%d ", b[j++]);
	return 0;
}