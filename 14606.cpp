#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int s[11];

int sol(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	int m = 0;
	for (int i = 1, a, b, l = n / 2; i <= l; i++) {
		if (s[n - i] == -1)
			s[n - i] = sol(n - i);
		if (s[i] == -1)
			s[i] = sol(i);
		m = max(m, s[n - i] + s[i] + (n - i)*i);
	}
	return m;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i <= 10; i++)
		s[i] = -1;
	printf("%d", sol(n));
	return 0;
}