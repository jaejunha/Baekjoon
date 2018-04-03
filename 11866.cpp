#include <stdio.h>
#include<queue>

using namespace std;

int main() {

	int int_n, int_m;
	queue<int> queue;
	scanf("%d %d", &int_m, &int_n);
	for (int i = 0; i < int_m; i++)
		queue.push(i + 1);
	printf("<");
	while (queue.size()>0) {
		for (int j = 0; j < int_n - 1; j++) {
			queue.push(queue.front());
			queue.pop();
		}
		if (queue.size() == 1)
			printf("%d", queue.front());
		else
			printf("%d, ", queue.front());
		queue.pop();
	}
	printf(">");
	return 0;
}