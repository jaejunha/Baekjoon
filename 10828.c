#include <stdio.h>
#include <string.h>

int main() {

	int int_n;
	char string_command[10];
	int int_arg;
	int int_top = -1;
	int stack[10000];
	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%s %d", string_command, &int_arg);
		if (!strcmp(string_command, "push")) {
			stack[int_top+++1] = int_arg;
		}
		else if (!strcmp(string_command, "pop")) {
			if (int_top != -1)
				printf("%d\n", stack[int_top--]);
			else
				printf("-1\n");

		}else if (!strcmp(string_command, "size")) {
			printf("%d\n", int_top + 1);

		}else if (!strcmp(string_command, "empty")) {
			int_top == -1 ? printf("1\n") : printf("0\n");

		}else if (!strcmp(string_command, "top")) {
			if (int_top != -1)
				printf("%d\n", stack[int_top]);
			else
				printf("-1\n");
		}
	}
	return 0;
}