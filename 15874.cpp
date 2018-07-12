#include <iostream>
using namespace std;

char T[26], t[26];
char s[100001];
int n, k;
int main() {
	scanf("%d%d\n", &k, &n);
	k %= 26;
	for (char c = 'A'; c <= 'Z'; c++) {
		T[(c - 'A' - k + 26) % 26] = c;
	}for (char c = 'a'; c <= 'z'; c++) {
		t[(c - 'a' - k + 26) % 26] = c;
	}
	char temp;
	for (int i = 1; i <= n; i++) {
		scanf("%c", &temp);
		if (temp >= 'a' && temp <= 'z')
			s[i] = t[(temp - 'a' + 26) % 26];
		else if (temp >= 'A' && temp <= 'Z')
			s[i] = T[(temp - 'A' + 26) % 26];
		else
			s[i] = temp;
	}
	for (int i = 1; i <= n; i++)
		printf("%c", s[i]);
	return 0;
}