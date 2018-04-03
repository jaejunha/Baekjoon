#include <stdio.h>
#include <vector>

using namespace std;

int array_seq[100000];
int stack[100000];
vector<char> vec_answer;

int main() {

	int int_n;
	int int_top = -1;
	int int_cursor = 0;
	int int_i = 1;
	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++)
		scanf("%d", &array_seq[i]);

	for (int i = 1; i <= array_seq[int_cursor]; i++) {
		vec_answer.push_back('+');
		stack[int_top + 1] = int_i++;
		int_top++;
	}
	vec_answer.push_back('-');
	int_top--;
	int_cursor++;

	while (int_cursor < int_n) {
		if (array_seq[int_cursor] == stack[int_top]) {
			vec_answer.push_back('-');
			int_top--;
			int_cursor++;
		}
		else if (array_seq[int_cursor] > stack[int_top]) {
			if (int_i > int_n) {
				printf("NO");
				return 0;
			}
			vec_answer.push_back('+');
			stack[int_top + 1] = int_i++;
			int_top++;
		}
		else {
			printf("NO");
			return 0;
		}
	}
	if (int_top != -1) {
		printf("NO");
		return 0;
	}

	for (auto answer : vec_answer) printf("%c\n", answer);

	return 0;
}