#include <iostream>
#include <algorithm>
using namespace std;

int l, a, b, c, d;

int main() {
	scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);
	int x = ((a%c) == 0) ? a / c : a / c + 1;
	int y = ((b%d) == 0) ? b / d : b / d + 1;
	printf("%d", l - max(x, y));

	return 0;
}