#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
bool dp[1001];
int main() {

	vector<int> v;
	for (int i = 1, s = 0;; i++) {
		s += i;
		if (s > 1000)
			break;
		v.push_back(s);
		dp[3 * s] = true;
	}
	int l = v.size();
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (i != j && (v[i] * 2 + v[j] <= 1000))
				dp[v[i] * 2 + v[j]] = true;
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			for (int k = j + 1; k < l; k++)
				if (v[i] + v[j] + v[k] <= 1000)
					dp[v[i] + v[j] + v[k]] = true;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (dp[n])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}