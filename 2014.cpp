/* reference: http://mygumi.tistory.com/183 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int k, n;
long long a[101], h;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &a[i]);
		q.push(a[i]);
	}
	for (int i = 0; i < n; i++) {
		h = q.top();
		q.pop();
		for (int j = 0; j < k; j++) {
			q.push(h*a[j]);
			if (!(h % a[j]))
				break;
		}
	}

	printf("%lld", h);
	return 0;
}