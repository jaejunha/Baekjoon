#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> v, u;
string t;
int s;

int main() {
	scanf("%d%d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 1; i <= m; i++) {
		cin >> t;
		if (binary_search(v.begin(), v.end(), t)) {
			s++;
			u.push_back(t);
		}
	}
	sort(u.begin(), u.end());
	printf("%d\n", s);
	for (string str : u)
		cout << str << endl;
	return 0;
}