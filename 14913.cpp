#include <cstdio>
using namespace std;

int a, d, k;

int main() {
	scanf("%d%d%d", &a, &d, &k);
	if (a == k)
		printf("1");
	else {
		if (d == 0)
			printf("X");
		else {
			int t = k - a;
			if (t%d)
				printf("X");
			else {
				if (t / d < 0)
					printf("X");
				else
					printf("%d", 1 + t / d);
			}
		}
	}
	return 0;
}