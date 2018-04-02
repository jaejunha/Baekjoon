#include <stdio.h>
#include <string.h>

int stack[31];

int main() {
	char array_input[31];
	int int_top = -1;
	int is_beforePop = 0;
	int int_level = 1;
	int int_sum = 0;
	scanf("%s", array_input);

	for (int i = 0, length = strlen(array_input); i < length; i++) {
		if (array_input[i] == '(' || array_input[i] == '[') {
			if (int_top == 29) {
				printf("0");
				return 0;
			}
			else {
				int_top++;
				if (array_input[i] == '(') {
					stack[int_top] = 2;
					int_level *= 2;
				}
				else {
					stack[int_top] = 3;
					int_level *= 3;
				}
			}
			is_beforePop = 0;
		}
		else {
			if (int_top == -1) {
				printf("0");
				return 0;
			}
			if (array_input[i] == ')') {
				if (stack[int_top] == 3) {
					printf("0");
					return 0;
				}
				else {
					if (is_beforePop == 0)
						int_sum += int_level;
					int_level /= 2;
				}
			}
			else {
				if (stack[int_top] == 2) {
					printf("0");
					return 0;
				}
				else {
					if (is_beforePop == 0)
						int_sum += int_level;
					int_level /= 3;
				}
			}
			int_top--;
			is_beforePop = 1;
		}

		if (i == length - 1) {
			if (int_top != -1) {
				printf("0");
				return 0;
			}
		}
	}
	printf("%d", int_sum);
	return 0;
}