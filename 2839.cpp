#include <stdio.h>

using namespace std;

int int_a[5001];

int a(int n) {
	if (n == 0)
		return 0;
	if (n == 3)
		return 1;
	if (n == 5)
		return 1;
	if (n <= 4) {
		return 5000;
	}

	if (int_a[n] != 0)
		return int_a[n];

	int_a[n - 3] = a(n - 3);
	int_a[n - 5] = a(n - 5);
	if (int_a[n - 3] < int_a[n - 5])
		return int_a[n - 3] + 1;
	else
		return int_a[n - 5] + 1;
}

int main() {

	int int_n;
	int int_answer;
	scanf("%d", &int_n);
	int_a[1] = int_a[2] = int_a[4] = -1;
	int_answer = a(int_n);
	if (int_answer<5000)
		printf("%d", int_answer);
	else
		printf("-1");

	return 0;
}