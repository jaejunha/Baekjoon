/* reference: http://blog.naver.com/PostView.nhn?blogId=programmer18&logNo=220876732845 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100001];
bool b[100001];
int c, d;
long long s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	while (c < n && d < n) {
		if (b[a[d]]) {
			s += d - c;
			b[a[c]] = false;
			c++;
		}
		else {
			b[a[d]] = true;
			d++;
		}
	}
	printf("%lld", s + (long long)(d - c)*(d - c + 1) / 2);
	return 0;
}