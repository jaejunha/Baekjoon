#include <iostream>
#include <cstring>
using namespace std;

char c[5];

int main() {
	scanf("%s", c);
	int l = strlen(c);
	if (l == 2)
		printf("%d", c[0] - '0' + c[1] - '0');
	else if (l == 3) {
		if (c[2] == '0')
			printf("%d", c[0] - '0' + (c[1] - '0') * 10 + c[2] - '0');
		else
			printf("%d", (c[0] - '0') * 10 + c[1] - '0' + c[2] - '0');
	}
	else
		printf("%d", (c[0] - '0') * 10 + c[1] - '0' + (c[2] - '0') * 10 + c[3] - '0');

	return 0;
}