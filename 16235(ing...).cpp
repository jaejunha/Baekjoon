#include <iostream>
#include <ctime>
using namespace std;
typedef struct{
	int x, y, z;
}Tree;

Tree tree[101];

int main() {
	ios_base::sync_with_stdio(false);
	
	int start = clock();
	int N, M, K;
	int A[11][11];
	register int *p = A[0];
	register Tree *q = &tree[0];
	cin >> N >> M >> K;
	int S = N * N;
	for (register int i = 1, t; i <= S; i++) {
		cin >> t;
		*p++ = t;
	}
	for (register int i = 1, x, y, z; i <= M; i++) {
		cin >> x >> y >> z;
		q->x = x;
		q->y = y;
		q->z = z;
		q++;
	}
	p = A[0];

	for (register int i = 1; i <= S; i++) {
		cout << *p++;
	}
	cout << '\n'<< clock() - start << '\n';
	cin >> N;
	return 0;
}
