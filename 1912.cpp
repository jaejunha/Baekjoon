#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s[100000];
int m = -1000;
int main() {

	scanf("%d", &n);
	for (int i = 0, t; i < n; i++) {
		scanf("%d", &t);
		if (i > 0)
			s[i] = max(s[i - 1] + t, t);
		else
			s[i] = t;
	}

	for (int i = 0; i < n; i++)
		m = max(m, s[i]);
	printf("%d", m);

	return 0;
}