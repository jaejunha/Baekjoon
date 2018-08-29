#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char s[11];
int l, ans;
int main() {
	bool b = false;
	scanf("%s", s);
	l = strlen(s);
	sort(s, s + l);
	do {
		b = true;
		for (int i = 0; i < l - 1; i++) {
			if (s[i] == s[i + 1]) {
				b = false;
				break;
			}
		}
		if (b) ans++;
	} while (next_permutation(s, s + l));
	printf("%d", ans);
	return 0;
}