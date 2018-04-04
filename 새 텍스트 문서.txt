#include <stdio.h>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
priority_queue<int> priority;

int main() {

	int int_counter;
	int int_m, int_n;
	int int_value;
	int int_temp;
	int int_result;
	scanf("%d", &int_counter);
	for (int i = 0; i < int_counter; i++) {
		scanf("%d %d", &int_m, &int_n);
		while (q.size() > 0) q.pop();
		while (priority.size() > 0) priority.pop();
		int_result = 0;
		for (int j = 0; j < int_m; j++) {
			scanf("%d", &int_temp);
			q.push({ int_temp,j });
			priority.push(int_temp);
			if (j == int_n)
				int_value = int_temp;
		}

		while (1) {
			while (q.front().first != priority.top()) {
				q.push({ q.front().first,q.front().second });
				q.pop();
			}
			if (priority.top() == int_value) {
				while (q.front().second != int_n) {
					int temp = q.front().first;
					q.push({ q.front().first,q.front().second });
					q.pop();
					if (temp == int_value) {
						priority.pop();
						int_result++;
					}
				}
				printf("%d\n", int_result + 1);
				break;
			}
			priority.pop();
			q.pop();
			int_result++;
		}
	}
	return 0;
}