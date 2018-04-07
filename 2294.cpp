#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int array_k[10001];
vector<int> vec_n;
int int_n, int_k;

int main() {
	scanf("%d %d", &int_n, &int_k);
	vec_n.resize(int_n);
	for (int i = 1; i <= int_k; i++)
		array_k[i] = 10001;
	for (int i = 0; i < int_n; i++) {
		scanf("%d", &vec_n[i]);
		for (int j = vec_n[i]; j <= int_k; j++) {
			array_k[j] = min(array_k[j], array_k[j - vec_n[i]] + 1);
		}
	}
	if (array_k[int_k] == 10001)
		printf("-1");
	else
		printf("%d", array_k[int_k]);

	return 0;
}