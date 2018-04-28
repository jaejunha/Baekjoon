#include <stdio.h>
#include <algorithm>

using namespace std;

int tree[10000001];
long long a[100001];
long long r;
int n;

int makeTree(int start, int end, int index) {
	if (end == start)
		return (tree[index] = start);
	int mid = (start + end) / 2;
	int t_a = makeTree(start, mid, index * 2);
	int t_b = makeTree(mid + 1, end, index * 2 + 1);

	if (a[t_a] <= a[t_b])
		tree[index] = t_a;
	else
		tree[index] = t_b;

	return tree[index];
}

int query(int left, int right, int start, int end, int index) {
	if (start > right || end < left)
		return -1;

	if (start <= left && right <= end)
		return tree[index];
	int mid = (left + right) / 2;
	int idx1 = query(left, mid, start, end, 2 * index);
	int idx2 = query(mid + 1, right, start, end, 2 * index + 1);

	if (idx1 == -1)
		return idx2;
	else if (idx2 == -1)
		return idx1;
	if (a[idx1] > a[idx2])
		return idx2;
	else
		return idx1;
}

void solution(int start, int end) {
	if (start == end)
		r = max(r, a[start]);
	else {
		int idx = query(1, n, start, end, 1);
		r = max(r, (end - start + 1)*a[idx]);
		if (idx > start)
			solution(start, idx - 1);
		if (idx < end)
			solution(idx + 1, end);
	}
}

int main() {

	while (true) {
		scanf("%lld", &n);
		if (n == 0)
			break;
		for (int i = 1; i <= n; scanf("%d", &a[i++]));

		makeTree(1, n, 1);
		r = 0;
		solution(1, n);
		printf("%lld\n", r);
	}
	return 0;
}