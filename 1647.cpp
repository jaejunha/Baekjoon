#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;
int n, m, s;
vector<pair<int, P>> v;
int p[100001];

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	p[x] = y;
}

int main() {
	int a, b, c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		v.push_back({ c,{ a,b } });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		if (n <= 2)
			break;
		a = find(i.second.first);
		b = find(i.second.second);
		if (a != b) {
			merge(a, b);
			s += i.first;
			n--;
		}
	}
	printf("%d", s);
	return 0;
}