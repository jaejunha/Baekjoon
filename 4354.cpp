/* reference: http://deque.tistory.com/81 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int length;
int sol;
char str[1000001];
int pi[1000001];

int main() {
	while (1) {
		scanf("%s", str);
		if (str[0] == '.')
			return 0;
		length = strlen(str);
		if (length >= 2) {
			fill(pi, pi + 1000001, 0);
			for (int i = 1, j = 0; i < length; i++) {
				while (j > 0 && str[i] != str[j])
					j = pi[j - 1];
				if (str[i] == str[j])
					pi[i] = ++j;
			}
			sol = pi[length - 1];
			if (sol == 0 || ((length % (length - sol)) != 0))
				printf("1\n");
			else
				printf("%d\n", length / (length - sol));
		}
		else
			printf("1\n");
	}
	return 0;
}