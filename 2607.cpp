#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char w[101];
int a[26];
int l_a;

char t[101];
int b[26];
int l_b;

vector<pair<char, int>> v;

int c;
int s;

int main() {
	scanf("%d", &n);
	scanf("%s", w);
	l_a = strlen(w);
	for (int i = 0; i < l_a; i++)
		a[w[i] - 'A']++;

	for (int i = 1; i < n; i++) {
		scanf("%s", t);
		l_b = strlen(t);
		if (abs(l_a - l_b) < 2) {
			c = 0;
			v.clear();
			for (int j = 0; j < l_b; j++)
				b[t[j] - 'A']++;
			for (int j = 0; j < 26; j++) {
				if (abs(a[j] - b[j]) >= 2) {
					c = -1;
					break;
				}
				if (a[j] - b[j]) {
					c++;
					v.push_back({ j + 'A',abs(a[j] - b[j]) });
				}
			}
			if (c != -1) {
				if (c <= 1)
					s++;
				else if (v.size() == 2 && v[0].second == 1 && v[1].second == 1)
					s++;
			}
		}
		if (i != n - 1) {
			for (int j = 0; j < 26; j++)
				b[j] = 0;
			for (int j = 0; j < l_b; j++)
				t[j] = 0;
		}
	}
	printf("%d", s);
	return 0;
}