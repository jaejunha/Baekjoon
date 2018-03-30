#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

	char array_buffer[11];
	int array_int[11];
	int int_n=0;
	scanf("%s", array_buffer);
	for (int i = 0; i < 11; i++, int_n++) {
		if (!(array_buffer[i] >= '0' &&array_buffer[i] <= '9'))
			break;
		array_int[i] = array_buffer[i] - '0';
	}
	sort(array_int, array_int + int_n, greater<int>());
	for (int i = 0; i < int_n; i++)
		printf("%d",array_int[i]);
	return 0;
}