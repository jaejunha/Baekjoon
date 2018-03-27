#include <stdio.h>

int main() {

	int int_counter;
	int int_input[4];
	char char_letter[6] = "DCBAE";
	
	for (int i = 0; i < 3; i++) {
		int_counter = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &int_input[j]);
		}
		for (int j = 0; j < 4; j++) {
			if (int_input[j] == 1)
				int_counter++;
		}
		printf("%c\n", char_letter[int_counter]);
	}
	return 0;
}