#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, l, d;
char a[101];

int main() {
	scanf("%d\n", &n);
	while (n--) {
		scanf("%s\n", a);
		l = strlen(a);
		d = a[l - 1] - '0';
		if (d % 2)
			printf("odd\n");
		else
			printf("even\n");

	}
	return 0;
}