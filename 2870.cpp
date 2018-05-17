#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<char *> v;
char c[101];
char *t;
char *p, *q;

bool comp(const char *a, const char *b) {
	int l_a, l_b;
	l_a = strlen(a);
	l_b = strlen(b);
	if (l_a != l_b)
		return l_a < l_b;
	else {
		for (int i = 0; i < l_a; i++) {
			if (a[i] != b[i])
				return a[i] < b[i];
			if (i == l_a - 1)
				return 0;
		}
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		p = c;
		while (*p) {
			if (*p >= 'a' && *p <= 'z')
				p++;
			else {
				q = p;
				while (*(q + 1) && *(q + 1) >= '0' && *(q + 1) <= '9')
					q++;
				if (q != p && *p == '0') {
					while (p < q && *p == '0')
						p++;
				}
				t = new char[q - p + 2];
				memset(t, 0, q - p + 2);
				strncpy(t, p, q - p + 1);
				v.push_back(t);
				p = q + 1;
			}
		}
	}
	sort(v.begin(), v.end(), comp);
	for (auto i = v.begin(); i != v.end(); i++)
		printf("%s\n", *i);
	return 0;
}