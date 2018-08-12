#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> a = { 2,3,5,7 };
int b[] = { 1,3,7,9 };

bool check(int t) {
	int l = sqrt(t);
	for (int i = 2; i <= l; i++) {
		if (!(t%i))
			return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		for (int i : a)
			printf("%d\n", i);
	}
	else {
		int t;
		vector<int> v;
		for (int i = 2; i <= n; i++) {
			for (int j : a) {
				for (int k : b) {
					t = j * 10 + k;
					if (check(t))
						v.push_back(t);
				}
			}
			a = v;
			v.clear();
		}
		for (int i : a)
			printf("%d\n", i);
	}
	return 0;
}