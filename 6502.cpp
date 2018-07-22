#include <iostream>
using namespace std;

int r, w, l;

int main() {
	int i = 1;
	while (1) {
		scanf("%d", &r);
		if (!r)
			break;
		scanf("%d%d", &w, &l);
		if (4 * r*r >= w*w + l*l)
			printf("Pizza %d fits on the table.\n", i++);
		else
			printf("Pizza %d does not fit on the table.\n", i++);
	}
	return 0;
}