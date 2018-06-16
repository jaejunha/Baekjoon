#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> C;

int u[10000];

int n, e;
int s;
vector<C> v;

int find(int i) {
	if (i == u[i])
		return i;
	return (u[i] = find(u[i]));
}

bool merge(int i, int j) {
	int a = find(i);
	int b = find(j);
	if (a == b)
		return false;
	u[a] = b;
	return true;
}

int main() {
	scanf("%d%d", &n, &e);
	for (int i = 1, x, y, z; i <= e; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({ z,{ x,y } });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		u[i] = i;
	for (int i = 0; i < e; i++) {
		if (merge(v.at(i).second.first, v.at(i).second.second))
			s += v.at(i).first;
	}
	printf("%d", s);
	return 0;
}