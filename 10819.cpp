#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;
int s;
int answer;
int c;
int main() {
	scanf("%d", &n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	do {
		s = 0;
		c++;
		for (int i = 0; i < n - 1; i++)
			s += abs(v[i] - v[i + 1]);
		answer = max(answer, s);
	} while (next_permutation(v.begin(), v.end()));
	printf("%d", answer);
}