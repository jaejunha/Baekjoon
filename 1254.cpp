#include <iostream>
#include <cstring>
using namespace std;

char s[1001];

bool check(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (s[i] != s[r])
			return false;
		r--;
	}
	return true;
}

int main() {
	scanf("%s", s);
	if (check(0, strlen(s) - 1))
		printf("%d", strlen(s));
	else {
		int l = strlen(s) - 1;
		for (int i = 0; i < l; i++) {
			if (check(i + 1, l)) {
				printf("%d", l + i + 2);
				return 0;
			}
		}
		printf("%d", 2 * (l + 1));
	}
	return 0;
}