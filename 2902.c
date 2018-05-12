#include <stdio.h>
#include <string.h>

char str[101];

int main() {
	scanf("%s", str);

	for (int i = 0, l = strlen(str); i < l; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			printf("%c", str[i]);
	}

	return 0;
}