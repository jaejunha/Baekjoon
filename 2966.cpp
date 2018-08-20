#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a, b, c;
char x[] = "ABC";
char y[] = "BABC";
char z[] = "CCAABB";
char s[101];
int main() {
	scanf("%d\m", &n);
	scanf("%s", s);

	for (int i = 0; i < n; i++) {
		if (s[i] == x[i % 3])
			a++;
		if (s[i] == y[i % 4])
			b++;
		if (s[i] == z[i % 6])
			c++;
	}
	int m = max(a, max(b, c));
	printf("%d\n", m);
	if (m == a)
		printf("Adrian\n");
	if (m == b)
		printf("Bruno\n");
	if (m == c)
		printf("Goran\n");

	return 0;
}