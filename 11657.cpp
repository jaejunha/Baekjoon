/* reference: http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220796963742 */
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

typedef pair<int, int> P;

int n, m, d[6001];
vector<P> v[6001];

int main() {

	scanf("%d%d", &n, &m);
	for (int x, y, z; m--;) {
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back({ y,z });
	}

	fill(d, d + 6001, 60000000);
	d[1] = 0;
	for (int i = 1, x, y; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto it : v[j]) {
				x = it.first;
				y = it.second;
				if (d[j] != 60000000 && d[x] > d[j] + y) {
					d[x] = d[j] + y;
					if (i == n) {
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (d[i] != 60000000)
			printf("%d\n", d[i]);
		else
			printf("-1\n");
	}

	return 0;
}