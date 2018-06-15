/* reference: http://dhpark.kr/662 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
int n, m;
int u[1000];
vector <pair<int, P>> e;

long long s;

int find(int i) {
	if (i == u[i])
		return i;
	return (u[i] = find(u[i]));
}

bool merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b)
		return false;
	u[b] = a;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y, z; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		e.push_back({ z,{ x,y } });
	}
	sort(e.begin(), e.end());
	for (int i = 0; i < n; i++)
		u[i] = i;
	for (int i = 0; i < m; i++) {
		if (merge(e.at(i).second.first, e.at(i).second.second))
			s += e.at(i).first;
	}

	printf("%lld", s);

	return 0;
}