#include <stdio.h>
#include <algorithm>

using namespace std;

int t;
int N, L;
int mn, mx;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &L, &N);
		mx = mn = 0;
		for (int j = 0, a; j < N; j++) {
			scanf("%d", &a);
			mx = max(mx, max(a, L - a));
			mn = max(mn, min(a, L - a));
		}
		printf("%d %d\n", mn, mx);
	}

	return 0;
}