#include <stdio.h>

int main() {

	int int_n;
	int int_score, int_count, int_time;
	int int_i = 0;

	int int_maxScore = 0;
	int int_maxCount = 0;
	int int_maxTime = 0;

	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%d %d %d", &int_score, &int_count, &int_time);
		if (int_maxScore == int_score) {
			if (int_maxCount == int_count) {
				if (int_maxTime > int_time) {
					int_maxScore = int_score;
					int_maxCount = int_count;
					int_maxTime = int_time;
					int_i = i + 1;
				}
			}
			else if (int_maxCount > int_count) {
				int_maxScore = int_score;
				int_maxCount = int_count;
				int_maxTime = int_time;
				int_i = i + 1;
			}
		}
		else if (int_maxScore < int_score) {
			int_maxScore = int_score;
			int_maxCount = int_count;
			int_maxTime = int_time;
			int_i = i + 1;
		}
	}
	printf("%d", int_i);

	return 0;
}