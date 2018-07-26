#include <iostream>
#include <cstring>
using namespace std;

char a[333335];
bool b;
int main() {
	scanf("%s", a);
	if (a[0] == '0')
		printf("0");
	else {
		int l = strlen(a);
		for (int i = 0, j; i < l; i++) {
			j = a[i] - '0';
			if (i == 0) {
				if (j / 4) {
					printf("%d", j / 4);
					b = true;
				}
			}
			else
				printf("%d", j / 4);
			j = j % 4;
			if (i == 0 && !b) {
				if (j == 2 || j == 3)
					printf("%d%d", j / 2, j % 2);
				else
					printf("1");
			}
			else
				printf("%d%d", j / 2, j % 2);
		}
	}
	return 0;
}