/* reference: http://wootool.tistory.com/97 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000];
int dp[1000];
int m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				mx = max(mx, dp[j]);
		}
		dp[i] = mx + a[i];
		m = max(m, dp[i]);
	}
	printf("%d", m);
	return 0;
}