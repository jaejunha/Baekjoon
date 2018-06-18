/* reference: http://codersbrunch.blogspot.com/2017/07/1693.html */
/* reference: https://www.slideshare.net/ssuser81b91b/4-dynamic-programming1 */
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v[100001];
bool b[100001];
int dp[100001][18];
int s = 987654321;

void color(int p) {
	for (int i = 1; i <= 17; i++)
		dp[p][i] = i;
	for (int c : v[p]) {
		if (!b[c]) {
			b[c] = true;
			color(c);
			for (int i = 1, m; i <= 17; i++) {
				m = 987654321;
				for (int j = 1; j <= 17; j++) {
					if (i == j)
						continue;
					m = min(m, dp[c][j]);
				}
				dp[p][i] += m;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	b[1] = true;
	color(1);
	for (int i = 1; i <= 17; i++)
		s = min(s, dp[1][i]);
	printf("%d", s);
	return 0;
}