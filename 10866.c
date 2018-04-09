#include <stdio.h>
#include <string.h>

int n, arg;
int q[100000];
int top, back;
int size;

char command[20];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", command, &arg);

		if (!strcmp(command, "push_front")) {
			if (size == 0) {
				q[top] = arg;
				back = top;
			}
			else {
				if (top == 0)
					top = 99999;
				else
					top--;
				q[top] = arg;
			}
			size++;
		}
		else if (!strcmp(command, "push_back")) {
			if (size == 0) {
				q[back] = arg;
				top = back;
			}
			else {
				if (back == 99999)
					back = 0;
				else
					back++;
				q[back] = arg;
			}
			size++;
		}
		else if (!strcmp(command, "pop_front")) {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[top]);
				if (top == 99999)
					top = 0;
				else
					top++;
				size--;
			}
		}
		else if (!strcmp(command, "pop_back")) {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[back]);
				if (back == 0)
					back = 99999;
				else
					back--;
				size--;
			}
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", size);
		}
		else if (!strcmp(command, "empty")) {
			if (size == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(command, "front")) {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[top]);
			}
		}
		else if (!strcmp(command, "back")) {
			if (size == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[back]);
			}
		}
	}

	return 0;
}