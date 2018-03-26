/* refer from : https://fatc.club/2017/03/01/278 */

#include <stdio.h>

int main() {
	long int_count;
	long int_a, int_b;
	long int_sub;
	long int_dist;
	long int_stage;
	scanf("%d", &int_count);
	for (int i = 0; i < int_count; i++) {
		scanf("%d %d", &int_a, &int_b);
		int_sub = int_b - int_a;
		int_dist = 0;
		int_stage = 1;
		while (1) {
			int_dist += int_stage;
			if (int_sub <= int_dist) {
				printf("%d\n",2 * int_stage - 1);
				break;
			}
			int_dist += int_stage;
			if (int_sub <= int_dist) {
				printf("%d\n", 2 * int_stage);
				break;
			}
			int_stage++;
		}
	}

	return 0;
}