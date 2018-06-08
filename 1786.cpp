/* reference: http://deque.tistory.com/79 */
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string t, p;
int pi[1000000];
int n, m;
int c;
vector<int> r;

int main() {
	getline(cin, t);
	getline(cin, p);
	n = t.size();
	m = p.size();
	for (int i = 1, j = 0; i < m; i++) {
		while (j && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	for (int i = 0, j = 0; i < n; i++) {
		while (j && t[i] != p[j])
			j = pi[j - 1];
		if (t[i] == p[j]) {
			if (j == m - 1) {
				c++;
				r.push_back(i - m + 2);
				j = pi[j];
			}
			else
				j++;
		}
	}
	printf("%d\n", c);
	for (auto it : r)
		printf("%d\n", it);
	return 0;
}