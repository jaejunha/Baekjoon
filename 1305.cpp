/* reference: http://vvshinevv.tistory.com/9 */
#include <cstdio>
#include <cstring>

int l;
char t[1000001];
int pi[1000001];
int main() {
	scanf("%d", &l);
	scanf("%s", t);
	for (int i = 1, j = 0; i < l; i++) {
		while (j && t[i] != t[j])
			j = pi[j - 1];
		if (t[i] == t[j])
			pi[i] = ++j;
	}
	printf("%d", l - pi[l - 1]);

	return 0;
}