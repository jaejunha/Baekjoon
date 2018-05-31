#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<long long> s;

int main() {

	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	s.resize(n);
	for (int i = 1; i <= n; i++)
		s.at(i - 1) = v.at(i - 1) * (n - i + 1);
	
	sort(s.begin(), s.end());
	printf("%lld", s.at(n - 1));
	return 0;
}