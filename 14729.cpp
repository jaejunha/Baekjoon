#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<double> v;

int main() {
	scanf("%d", &n);
	double x;
	for (int i = 0, j; i < n; i++) {
		scanf("%lf", &x);
		if (i < 7) {
			v.push_back(x);
			if (i == 6)
				sort(v.begin(), v.end());
		}
		else {
			j = lower_bound(v.begin(), v.end(), x) - v.begin();
			if (j < 7) {
				for (int k = 5; k >= j; k--)
					v[k + 1] = v[k];
				v[j] = x;
			}
		}
	}
	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", v[i]);
	return 0;
}