#include <stdio.h>
#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s;
string a;
int main() {

	cin >> a;
	for (int i = 0, l = a.length(); i < l; i++) {
		for (int j = i; j < l; j++) {
			s.insert(a.substr(i, j - i + 1));
		}
	}
	s.insert(a);
	printf("%d", s.size());
	return 0;
}