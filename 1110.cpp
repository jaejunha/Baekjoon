#include <iostream>
using namespace std;

int n, a, z, c;
bool b[100];
int main() {
	scanf("%d", &n);
	while (!b[n]) {
		b[n] = true;
		a = n / 10;
		z = n % 10;
		n = z * 10 + (a + z) % 10;
		c++;
	}
	printf("%d\n", c);
	return 0;
}