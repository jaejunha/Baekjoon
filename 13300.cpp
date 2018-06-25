#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int a[2][7];
int answer;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0, s, g; i < n; i++) {
		scanf("%d%d", &s, &g);
		a[s][g]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (a[i][j]) {
				if (a[i][j] % k == 0)
					answer += (a[i][j] / k);
				else
					answer += ((int)(a[i][j] / k) + 1);
			}
		}
	}
	printf("%d", answer);
	return 0;
}