/* reference: http://mrl.kr/boj2661/ */
#include <iostream>
#include <string>

using namespace std;

int n, c;
bool f;
string s;

bool check() {

	string x, y;
	for (int i = 1, l = c / 2; i <= l; ++i) {
		x = s.substr(c - i, i);
		y = s.substr(c - i * 2, i);
		if (x == y) {
			s = s.substr(0, c - 1);
			c--;
			return false;
		}
	}
	return true;
}

void dfs() {
	if (f)
		return;
	if (c == n) {
		cout << s;
		f = true;
		return;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			s += i + '0';
			c++;
			if (check()) {
				dfs();
				if (f)
					return;
			}
		}
		s = s.substr(0, c - 1);
		c--;
	}
}

int main() {
	scanf("%d", &n);

	dfs();
	return 0;
}