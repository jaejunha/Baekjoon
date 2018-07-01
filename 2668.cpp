#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int n;
int a[101];
set<int> s, t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}

	while (1) {
		for (auto i : s)
			t.insert(a[i]);
		if (s.size() == t.size()) {
			printf("%d\n", s.size());
			for (auto i : s)
				printf("%d\n", i);
			break;
		}
		s = t;
		t.clear();
	}
	return 0;
}