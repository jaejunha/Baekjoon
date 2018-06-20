/* reference: http://coding-start.tistory.com/17 */
#include <cstdio>
#include <vector>

using namespace std;

int k;
int l;
int s[20];

void dfs(int i, vector<int> v) {
	if (l == 6) {
		for (int x : v)
			printf("%d ", x);
		printf("\n");
	}
	else {
		for (int j = i + 1; j < k; j++) {
			l++;
			vector<int> u = v;
			u.push_back(s[j]);
			dfs(j, u);
		}
	}

	l--;
}

int main() {
	while (1) {
		scanf("%d", &k);
		if (!k)
			break;
		for (int i = 0; i<k; scanf("%d", &s[i++]));
		for (int i = 0; i < k; i++) {
			l = 1;
			vector<int> v;
			v.push_back(s[i]);
			dfs(i, v);
		}
		printf("\n");
	}
	return 0;
}