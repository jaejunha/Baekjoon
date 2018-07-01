#include <cstdio>
using namespace std;

int n;
bool b[1000000];
bool a[1000000];
int s;

int main() {
	scanf("%d", &n);
	for (int i = 0, j; i < n; i++) {
		scanf("%d", &j);
		j ? b[i] = true : b[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i])
			continue;
		a[i] = !a[i];
		if (i < n - 1)
			a[i + 1] = !a[i + 1];
		if (i < n - 2)
			a[i + 2] = !a[i + 2];
		s++;
	}

	printf("%d", s);
	return 0;
}