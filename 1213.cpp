#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[51], s[51];
int c[26];

int main() {
	scanf("%s", a);
	int l = strlen(a);
	for (int i = 0; i < l; i++)
		c[a[i] - 'A']++;
	if (l % 2) {
		for (int i = 0, j = 0; i < 26; i++) {
			if (c[i] % 2) {
				j++;
				s[l / 2] = i + 'A';
			}
			if (j > 1) {
				printf("I'm Sorry Hansoo");
				return 0;
			}
		}
	}
	else {
		for (int i = 0, j = 0; i < 26; i++) {
			if (c[i] % 2) {
				printf("I'm Sorry Hansoo");
				return 0;
			}
		}
	}
	for (int i = 0, j = 0; i < 26; i++) {
		if (c[i] == 1)
			continue;
		while (c[i]) {
			s[j] = s[l - j - 1] = i + 'A';
			c[i] -= 2;
			j++;
		}
	}
	printf("%s", s);
	return 0;
}