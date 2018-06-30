#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, m;
int a[20][20];
int c;
int answer = 987654321;
void dfs(int x, vector<int> v) {
	if (c == m) {
		int b[20] = { 0, };
		for (int i : v)
			b[i] = 1;
		int s = 0, t = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (b[i] == b[j]) {
					if (b[i]) {
						s += a[i][j];
						s += a[j][i];
					}
					else {
						t += a[i][j];
						t += a[j][i];
					}
				}
			}
		}
		answer = min(answer, abs(s - t));
	}
	else {
		for (int i = x + 1; i < n; i++) {
			c++;
			vector<int> u = v;
			u.push_back(i);
			dfs(i, u);
		}
	}
	c--;
}
int main() {
	scanf("%d", &n);
	m = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 0; i < n; i++) {
		c = 1;
		vector<int> v;
		v.push_back(i);
		dfs(i, v);
	}
	printf("%d", answer);

	return 0;
}