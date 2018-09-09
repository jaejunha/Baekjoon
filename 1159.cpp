#include <iostream>
#include <algorithm>
using namespace std;

int n;
char a[31];
int c[26];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		c[a[0] - 'a']++;
	}

	bool ok = false;
	for (int i = 0; i < 26; i++) {
		if (c[i] >= 5) {
			printf("%c", i + 'a');
			ok = true;
		}
	}
	if (!ok)
		printf("PREDAJA");
	return 0;
}