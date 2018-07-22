#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[100002];
int z = -1, k, l;
bool comp(char a, char b) {
	return a > b;
}

int main() {
	scanf("%s", s);
	l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] - '0' == 0)
			z = i;
		k += (s[i] - '0');
	}
	if ((k % 3) || (z == -1))
		printf("-1");
	else {
		swap(s[l - 1], s[z]);
		sort(s, s + l - 1, comp);
		printf("%s", s);
	}

	return 0;
}