/* reference: http://codersbrunch.blogspot.kr/2016/05/1289.html */
#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int>> v[100001];
bool root[100001];
int n;
long long s;

long long dfs(int a, long long p) {

	long long x = 1, t;
	for (auto it = v[a].begin(); it != v[a].end(); it++) {
		if ((*it).first == p)
			continue;
		t = (dfs((*it).first, a)*(*it).second) % 1000000007;
		s = (s + (t*x)) % 1000000007;
		x = (x + t) % 1000000007;
	}
	return x;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, a, b, c; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dfs(1, 0);
	printf("%lld", s);
	return 0;
}