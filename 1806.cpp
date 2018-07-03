/* reference: http://codersbrunch.blogspot.com/2017/01/1806.html */
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int l;
int ans = 200000;
long long S;
long long s, ps[100001];

int main() {
	scanf("%d%lld", &n, &S);
	for (int i = 1, j = 0, x; i <= n; i++) {
		scanf("%d", &x);
		s += x;
		ps[i] = s;
		for (; ps[i] - ps[j] >= S; j++)
			ans = min(ans, i - j);
	}
	if (ans == 200000)
		printf("0");
	else
		printf("%d", ans);
	return 0;
}