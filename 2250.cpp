#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct Node {
	int left, right;
};

Node node[10001];
int w[10001];
vector<int> h[10001];
int idx = 1;
int root;
int num_level, max_width, max_level;

void dfs(int x, int l) {
	if (node[x].left != -1)
		dfs(node[x].left, l + 1);
	w[x] = idx++;
	h[l].push_back(x);
	num_level = max(num_level, l);
	if (node[x].right != -1)
		dfs(node[x].right, l + 1);
}

int main() {

	scanf("%d", &n);

	for (int i = 0, x, l, r; i < n; i++) {
		scanf("%d %d %d", &x, &l, &r);
		node[x].left = l;
		node[x].right = r;
		if (root == 0 || root == node[x].left || root == node[x].right)
			root = x;
	}

	dfs(root, 1);

	for (int i = 1, x, y; i <= num_level; i++) {
		x = 10001;
		y = 0;
		for (auto j = h[i].begin(); j != h[i].end(); j++) {
			x = min(x, w[*j]);
			y = max(y, w[*j]);
		}
		if (y - x + 1 > max_width) {
			max_level = i;
			max_width = y - x + 1;
		}
	}

	printf("%d %d", max_level, max_width);
	return 0;
}