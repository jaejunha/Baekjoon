/* reference: http://js1jj2sk3.tistory.com/93 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> Q;

int n, k;
int a[2001][2001];
vector<P> v;
queue<Q> q, r;
int p[100001];
int s;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int find(int x) {
	if (x == p[x])
		return x;
	else
		return (p[x] = find(p[x]));
}

void merge(int x, int y) {
	int i = find(x);
	int j = find(y);
	if (i != j)
		p[i] = j;
}

void check(int x, int y, int z) {
	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];

		if (px <= 0 || py <= 0 || px > n || py > n)
			continue;

		if (a[px][py]) {
			if (find(a[px][py]) != find(z)) {
				merge(z, a[px][py]);
				k--;
				if (k == 1) {
					printf("%d", s);
					return;
				}
			}
		}
	}

}

int main() {
	scanf("%d%d", &n, &k);
	v.resize(k + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &v[i].first, &v[i].second);
		a[v[i].first][v[i].second] = i;
		q.push({ v[i],i });
		p[i] = i;
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if (px <= 0 || py <= 0 || px > n || py > n)
				continue;
			if (a[px][py]) {
				if (find(z) != find(a[px][py])) {
					merge(z, a[px][py]);
					a[px][py] = z;
					k--;
				}
			}
		}
		r.push({ { x,y }, a[x][y] });
	}
	if (k != 1) {
		while (!r.empty()) {
			s++;
			int sz = r.size();
			for (int i = 0; i < sz; i++) {
				int x = r.front().first.first;
				int y = r.front().first.second;
				int z = r.front().second;
				r.pop();
				for (int i = 0; i < 4; i++) {
					int px = x + dx[i];
					int py = y + dy[i];
					if (px <= 0 || py <= 0 || px > n || py > n)
						continue;

					if (a[px][py])
						continue;

					a[px][py] = z;
					check(px, py, z);
					if (k == 1)
						return 0;
					r.push({ { px, py }, z });
				}
			}
		}
	}

	printf("%d", s);
	return 0;
}