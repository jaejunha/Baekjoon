/* reference: http://js1jj2sk3.tistory.com/17 */
#include <iostream>
using namespace std;

int a[201][201];
int p[201];
bool answer = true;

int find(int x) {
	if (x == p[x])
		return x;
	else
		return (p[x] = find(p[x]));
}

void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	if (i != j)
		p[i] = j;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1, x; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			if (x)
				merge(i, j);
		}
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d", &x);
		if (i == 1)
			y = find(x);
		else {
			if (y != find(x))
				answer = false;
		}
	}
	if (answer)
		printf("YES");
	else
		printf("NO");
	return 0;
}