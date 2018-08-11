#include <iostream>
using namespace std;

int p[101][101];
int n, k, l, t, d;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
pair<int, int> tail, head;
char c[10001];

int direction(int i, char j) {
	if (j == 'L')
		return (i + 3) % 4;
	else if (j == 'D')
		return (i + 5) % 4;
	return i;
}
int main() {
	scanf("%d%d", &n, &k);
	tail = head = { 1,1 };
	p[1][1] = d + 1;
	int x, y;
	while (k--) {
		scanf("%d%d", &x, &y);
		p[x][y] = -1;
	}
	scanf("%d", &l);
	while (l--) {
		scanf("%d", &x);
		scanf(" %c", &c[x]);
	}
	while (1) {
		t++;
		head = { head.first + dx[d], head.second + dy[d] };
		if (head.first > n || head.second > n || head.first < 1 || head.second < 1)
			break;
		if (p[head.first][head.second] > 0)
			break;
		if (p[head.first][head.second] != -1) {
			int tx = tail.first + dx[p[tail.first][tail.second] - 1];
			int ty = tail.second + dy[p[tail.first][tail.second] - 1];
			p[tail.first][tail.second] = 0;
			tail = { tx,ty };
		}
		d = direction(d, c[t]);
		p[head.first][head.second] = d + 1;
	}
	printf("%d", t);
	return 0;
}