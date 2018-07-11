/* reference: http://js1jj2sk3.tistory.com/20 */
#include <cstdio>
using namespace std;

int P, G;
int p[100001];
int s;

int find(int x) {
	if (x == p[x])
		return x;
	return (p[x] = find(p[x]));
}

void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	if (i != j)
		p[i] = j;
}

int main() {
	scanf("%d%d", &G, &P);
	for (int i = 1; i <= G; i++)
		p[i] = i;
	for (int i = 1, g, x; i <= P; i++) {
		scanf("%d", &g);
		x = find(g);
		if (x == 0)
			break;
		merge(x, x - 1);
		s++;
	}
	printf("%d", s);
	return 0;
}