#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, k, w;
int a[31][31];
int b[31][31];
vector<int> v;
int getMed(int i, int j, int w) {
	v.clear();
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < w; y++)
			v.push_back(a[i + x][j + y]);
	}
	sort(v.begin(), v.end());
	return v.at((int)(w*w) / 2);
}
int main() {

	scanf("%d %d %d %d", &m, &n, &k, &w);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < m - w + 1; i++) {
		for (int j = 0; j < n - w + 1; j++) {
			b[i][j] = getMed(i, j, w);
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}