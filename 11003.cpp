#include <stdio.h>
#include <deque>

using namespace std;

long n, l, a;
deque<pair<long, int>> d;

int main() {

	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		while (d.size() && d.front().second <= i - l)
			d.pop_front();
		scanf("%ld", &a);
		while (d.size() && d.back().first >= a)
			d.pop_back();
		d.push_back(make_pair(a, i));
		printf("%ld ", d.front().first);
	}
	return 0;
}