/* reference: http://blog.naver.com/PostView.nhn?blogId=ehddml1229&logNo=221013489684&beginTime=0&jumpingVid=&from=search&redirect=Log&widgetTypeCall=true */
/* reference: http://vvshinevv.tistory.com/27 */
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int x, n, d;
map<int, int> node;
long long c;

int main() {
	scanf("%d", &n);
	node.insert({ 0, -1 });
	node.insert({ 300001, -1 });
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		auto r = node.upper_bound(x);
		auto l = (--node.lower_bound(x));
		d = max(r->second, l->second) + 1;
		node.insert({ x,d });
		c += d;
		printf("%lld\n", c);
	}

	return 0;
}