#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct C {
	int x, y, z;
};

int t;
int n;
C c, d;
int g;
vector<C> v;
vector<int> node[3001];
stack<int> s;
bool b[3001];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.push_back({ 0,0,0 });
		for (int i = 1, x, y, z; i <= n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			c.x = x;
			c.y = y;
			c.z = z;
			v.push_back(c);
		}

		for (int i = 1; i < n; i++) {
			c = v.at(i);
			for (int j = i + 1; j <= n; j++) {
				d = v.at(j);
				if (((c.x - d.x)*(c.x - d.x) + (c.y - d.y)*(c.y - d.y)) <= ((c.z + d.z)*(c.z + d.z))) {
					node[i].push_back(j);
					node[j].push_back(i);
				}
			}
		}

		for (int i = 1, x; i <= n; i++) {
			if (b[i])
				continue;
			s.push(i);
			while (!s.empty()) {
				x = s.top();
				s.pop();
				b[x] = true;
				for (auto it : node[x]) {
					if (!b[it])
						s.push(it);
				}
			}
			g++;
		}
		printf("%d\n", g);

		if (t) {
			g = 0;
			v.clear();
			for (int i = 1; i <= n; i++) {
				node[i].clear();
				b[i] = false;
			}
		}
	}

	return 0;
}