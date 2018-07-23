#include <cstdio>
using namespace std;

int x, y;
int Rev(int a) {
	int s = 0;
	for (int i = a; i;) {
		s += (i % 10);
		i /= 10;
		if (i)
			s *= 10;
		else
			break;
	}
	return s;
}
int main() {
	scanf("%d%d", &x, &y);
	printf("%d\n", Rev(Rev(x) + Rev(y)));
	return 0;
}