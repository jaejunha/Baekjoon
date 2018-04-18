#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[1001], b[1001];
int s[1001][1001];
char answer[1001];

int main() {

	scanf("%s", a);
	scanf("%s", b);

	for (int i = 1, la = strlen(a); i <= la; i++) {
		for (int j = 1, lb = strlen(b); j <= lb; j++) {
			if (a[i - 1] == b[j - 1])
				s[i][j] = s[i - 1][j - 1] + 1;
			else
				s[i][j] = max(s[i - 1][j], s[i][j - 1]);
		}
	}

	for (int i = strlen(a), k = s[strlen(a)][strlen(b)]; i >= 1; i--) {
		for (int j = strlen(b); j >= 1; j--) {
			if ( (s[i][j] == k) && (a[i - 1] == b[j - 1]) ) {
				answer[k - 1] = a[i - 1];
				k--;
				break;
			}
		}
	}

	printf("%d\n%s", s[strlen(a)][strlen(b)], answer);
	return 0;
}