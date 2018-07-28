#include <iostream>
#include <cstring>
using namespace std;

char a[4][11];
char A[22], B[22];
long long x, y;
int main() {
	scanf("%s %s %s %s", a[0], a[1], a[2], a[3]);
	strcpy(A, a[0]);
	strcat(A, a[1]);
	strcpy(B, a[2]);
	strcat(B, a[3]);
	sscanf(A, "%lld", &x);
	sscanf(B, "%lld", &y);
	printf("%lld", x + y);
	return 0;
}