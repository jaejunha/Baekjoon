#include <stdio.h>
#include <string.h>

int n, l;
char s[101];

int main() {
	scanf("%d", &n);
	scanf("%c", &l);
	while (n--) {
		gets(s);
		for (int i = 0, j = 0; s[i]; i++) {
			if (j < 2) {
				if (s[i] == ' ') {
					j++;
					if (j == 2)
						l = i;
				}
			}
			else
				printf("%c", s[i]);
		}
		printf(" ");
		for (int i = 0; i < l; i++)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}