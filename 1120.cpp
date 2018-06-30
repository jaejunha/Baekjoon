#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int l_a, l_b, s = 100, c;
char a[51], b[51];
int main() {
	scanf("%s %s", a, b);
	if (strlen(a) > strlen(b)) {
		l_a = strlen(a);
		l_b = strlen(b);
	}
	else {
		l_a = strlen(b);
		l_b = strlen(a);
		swap(a, b);
	}
	for (int i = 0, l = l_a - l_b; i <= l; i++) {
		c = 0;
		for (int j = 0; j < l_b; j++) {
			if (a[j + i] != b[j])
				c++;
		}
		s = min(s, c);
	}
	printf("%d", s);
	return 0;
}