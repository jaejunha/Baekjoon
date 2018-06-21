#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long> p;
int n, c;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		if (!c) {
			if (p.empty())
				printf("0\n");
			else {
				printf("%lld\n", p.top());
				p.pop();
			}
		}
		else
			p.push(c);
	}
	return 0;
}