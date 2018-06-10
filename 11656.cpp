#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<string> v;

int main() {
	cin >> str;

	for (int i = 0, l = str.size(); i < l; i++)
		v.push_back(str.substr(i));

	sort(v.begin(), v.end());

	for (auto it : v)
		cout << it << endl;
	return 0;
}