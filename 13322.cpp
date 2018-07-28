#include <iostream>
#include <cstring>
using namespace std;
char s[100001];
int main() {
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++)
		printf("%d\n", i);
	return 0;
}
