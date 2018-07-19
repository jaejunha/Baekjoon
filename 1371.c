#include <stdio.h>
char s;
int c[26];

int main() {
	while (scanf("%c", &s) > 0) {
		if (s >= 'a' && s <= 'z')
			c[s - 'a']++;
	}
	int max = c[0];
	for (int i = 1; i < 26; i++) {
		if (c[i] > max)
			max = c[i];
	}
	for (int i = 0; i < 26; i++)
		if (c[i] == max)
			printf("%c", i + 'a');
}