/* reference: http://js1jj2sk3.tistory.com/19 */
#include <cstdio>
#include <algorithm>

using namespace std;

int p[300001];
bool b[300001];
int n, l;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	if (i != j)
		p[i] = j;
	printf("LADICA\n");
}

int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= l; i++)
		p[i] = i;
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		if (!b[x]) {
			b[x] = true;
			merge(x, y);
		}
		else if (!b[y]) {
			b[y] = true;
			merge(y, x);
		}
		else if (!b[find(x)]) {
			b[find(x)] = true;
			merge(x, y);
		}
		else if (!b[find(y)]) {
			b[find(y)] = true;
			merge(y, x);
		}
		else
			printf("SMECE\n");
	}
	return 0;
}