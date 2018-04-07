#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int int_m, int_n;
vector<int> vector_m;

int main() {

	scanf("%d", &int_m);
	vector_m.resize(int_m);
	for (int i = 0; i < int_m; i++)
		scanf("%d", &vector_m[i]);


	sort(vector_m.begin(), vector_m.end());

	scanf("%d", &int_n);
	for (int i = 0, temp; i < int_n; i++) {
		scanf("%d", &temp);
		printf("%d ", upper_bound(vector_m.begin(), vector_m.end(), temp) - lower_bound(vector_m.begin(), vector_m.end(), temp));
	}

	return 0;
}