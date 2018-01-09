#include <stdio.h>

int getCount(int size) {
	int sum = 1;
	for (int i = 0; i < size; i++) {
		sum *= 2;
	}
	return sum - 1;
}

void hanoi(int size, int from, int by, int to) {
	if (size == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(size - 1, from, to, by);
		hanoi(1, from, by, to);
		hanoi(size - 1, by, from, to);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", getCount(n));
	hanoi(n,1,2,3);
	return 0;
}