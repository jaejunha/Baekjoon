#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct u {
	int a;
	char b[101];
};

u c[100001];

bool cmp(const u &d, const u &e) {
	return d.a < e.a;
}


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %s", &c[i].a, &c[i].b);

	stable_sort(c, c + n, cmp);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", c[i].a, c[i].b);
	return 0;
}