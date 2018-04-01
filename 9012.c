#include <stdio.h>
#include <string.h>

int main() {
	int int_n;
	int int_top;
	char string_input[51];
	scanf("%d", &int_n);
	for (int i = 0, length; i < int_n; i++) {
		scanf("%s", string_input);
		int_top = -1;
		for (int j = 0, length = strlen(string_input); j < length; j++) {
			if (string_input[j] == '(')
				int_top++;
			else {
				if (int_top != -1)
					int_top--;
				else {
					printf("NO\n");
					break;
				}
			}
			if (j == length - 1)
				if (int_top == -1)
					printf("YES\n");
				else
					printf("NO\n");
		}
	}
	return 0;
}