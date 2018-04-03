#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

queue<int> list;

int main() {

	int int_n;
	char string_command[20];
	int int_arg;
	scanf("%d", &int_n);
	for (int i = 0; i < int_n; i++) {
		scanf("%s %d", string_command, &int_arg);
		if (!strcmp(string_command, "push")) {
			list.push(int_arg);
		}
		else if (!strcmp(string_command, "pop")) {
			if (list.size() <= 0)
				printf("-1\n");
			else {
				printf("%d\n", list.front());
				list.pop();
			}
		}
		else if (!strcmp(string_command, "front")) {
			if (list.size() <= 0)
				printf("-1\n");
			else
				printf("%d\n", list.front());

		}
		else if (!strcmp(string_command, "back")) {
			if (list.size() <= 0)
				printf("-1\n");
			else
				printf("%d\n", list.back());
		}
		else if (!strcmp(string_command, "empty")) {
			if (list.size() <= 0)
				printf("1\n");
			else
				printf("0\n");

		}
		else if (!strcmp(string_command, "size")) {
			printf("%d\n", list.size());
		}
	}
	return 0;
}