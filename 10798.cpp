#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s[5][16];
int l[5];
int m = 0;

int main() {

	for (int i = 0; i < 5; i++) {
		scanf("%s", s[i]);
		l[i] = strlen(s[i]);
		m = max(m, l[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			if (i<l[j])
				printf("%c", s[j][i]);
		}
	}

	return 0;
}