#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>

using namespace std;

typedef pair<long long, long long> P;
priority_queue<P, vector<P>, greater<P>> p;
int n, c;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		if (!c) {
			if (p.empty())
				printf("0\n");
			else {
				printf("%lld\n", p.top().second);
				p.pop();
			}
		}
		else
			p.push({ abs(c),c });
	}
	return 0;
}