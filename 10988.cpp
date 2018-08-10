#include <iostream>
#include <cstring>
using namespace std;

char s[101];

int check(int i, int j) {
	if (i > j)
		return 1;
	if (s[i] != s[j])
		return 0;
	return check(i + 1, j - 1);
}

int main() {
	scanf("%s", s);
	printf("%d", check(0, strlen(s) - 1));
	return 0;
}