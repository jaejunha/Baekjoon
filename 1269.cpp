#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c;
vector<int> u, v;

bool nsearch(int x, int l, int r) {
	int mt;
	int lt = l, rt = r;
	while (lt <= rt) {
		mt = (lt + rt) / 2;
		if (u[mt] == x)
			return true;
		else if (u[mt] > x)
			rt = mt - 1;
		else
			lt = mt + 1;
	}
	return false;
}

bool msearch(int x, int l, int r) {
	int mt;
	int lt = l, rt = r;
	while (lt <= rt) {
		mt = (lt + rt) / 2;
		if (v[mt] == x)
			return true;
		else if (v[mt] > x)
			rt = mt - 1;
		else
			lt = mt + 1;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	u.resize(n);
	v.resize(m);
	for (int i = 0; i < n; i++)
		scanf("%d", &u[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &v[i]);

	sort(u.begin(), u.end());
	sort(v.begin(), v.end());

	if (n > m) {
		for (int i = 0; i < m; i++) {
			if (nsearch(v[i], 0, n - 1))
				c++;
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (msearch(u[i], 0, m - 1))
				c++;
		}
	}

	printf("%d", n + m - 2 * c);

	return 0;
}