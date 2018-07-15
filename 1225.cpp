#include <iostream>
#include <cstring>
using namespace std;

char a[10001], b[10001];
long long s;
int main() {
	scanf("%s %s", a, b);
	int l_a = strlen(a);
	int l_b = strlen(b);
	for (int i = 0; i < l_a; i++) {
		for (int j = 0; j < l_b; j++) {
			s += (a[i] - '0') * (b[j] - '0');
		}
	}
	printf("%lld", s);
	return 0;
}