#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, d;
int a[20][20];
int z[6];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> p;
/*
0 ¹Ù´Ú
1 Á¤¸é
2 ÁÂ
3 À§
4 µÚ
5 ¿ì
*/
void rotate(int d) {
	int t;
	if (d == 1) {
		t = z[5];
		z[5] = z[3];
		z[3] = z[2];
		z[2] = z[0];
		z[0] = t;
	}
	else if (d == 2) {
		t = z[3];
		z[3] = z[5];
		z[5] = z[0];
		z[0] = z[2];
		z[2] = t;
	}
	else if (d == 3) {
		t = z[3];
		z[3] = z[1];
		z[1] = z[0];
		z[0] = z[4];
		z[4] = t;
	}
	else {
		t = z[1];
		z[1] = z[3];
		z[3] = z[4];
		z[4] = z[0];
		z[0] = t;
	}
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &p.first, &p.second, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	int px, py;
	while (k--) {
		scanf("%d", &d);
		px = p.first + dx[d - 1];
		py = p.second + dy[d - 1];
		if (px < 0 || py < 0 || px >= n || py >= m)
			continue;
		p = { px, py };
		rotate(d);
		if (!a[px][py])
			a[px][py] = z[0];
		else {
			z[0] = a[px][py];
			a[px][py] = 0;
		}
		printf("%d\n", z[3]);
	}

	return 0;
}