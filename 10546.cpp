#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int n, t;
char name[21];
map<string, int> list;
map<string, int>::iterator i;

int main() {
	scanf("%d", &n);
	for (n = 2 * n - 1; n--;) {
		scanf("%d", &t);
		scanf("%s", name);
		if ((i = list.find(name)) == list.end())
			list.insert(make_pair(name, 0));
		else
			list.erase(i);
	}
	cout << list.begin()->first;
	return 0;
}

