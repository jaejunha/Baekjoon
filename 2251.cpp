#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct P {
	int a, b, c;
}P;

int a, b, c;
bool v[201][201][201];
bool s[201];
queue<P> q;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	P p;
	p.a = 0;
	p.b = 0;
	p.c = c;
	q.push(p);
	s[c] = true;
	while (!q.empty()) {
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();
		if (v[x][y][z])
			continue;
		v[x][y][z] = true;
		for (int i = 0, px, py, pz, t; i < 6; i++) {
			switch (i) {
			case 0:
				if (!x)
					continue;
				if (y == b)
					continue;
				pz = z;
				t = x + y;
				py = min(t, b);
				px = t - py;
				break;
			case 1:
				if (!x)
					continue;
				if (z == c)
					continue;
				py = y;
				t = x + z;
				pz = min(t, c);
				px = t - pz;
				break;
			case 2:
				if (!y)
					continue;
				if (x == a)
					continue;
				pz = z;
				t = x + y;
				px = min(t, a);
				py = t - px;
				break;
			case 3:
				if (!y)
					continue;
				if (z == c)
					continue;
				px = x;
				t = y + z;
				pz = min(t, c);
				py = t - pz;
				break;
			case 4:
				if (!z)
					continue;
				if (x == a)
					continue;
				py = y;
				t = x + z;
				px = min(t, a);
				pz = t - px;
				break;
			case 5:
				if (!z)
					continue;
				if (y == b)
					continue;
				px = x;
				t = y + z;
				py = min(t, b);
				pz = t - py;
				break;
			}
			if (v[px][py][pz])
				continue;
			if (!s[pz] && !px)
				s[pz] = true;

			p.a = px;
			p.b = py;
			p.c = pz;
			q.push(p);
			q.push({ px,py,pz });
		}
	}

	for (int i = 0; i <= c; i++)
		if (s[i])
			printf("%d ", i);
	return 0;
}