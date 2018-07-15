/* reference: http://codersbrunch.blogspot.com/2016/06/1007-vector-matching.html */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> P;

int t, n;
bool b[20];
vector<P> v;
double answer;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &v[i].first, &v[i].second);
			b[i] = i % 2;
		}
		answer = 9999999999;
		do {
			long long x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				if (b[i]) {
					x += v[i].first;
					y += v[i].second;
				}
				else {
					x -= v[i].first;
					y -= v[i].second;
				}
			}
			answer = min(answer, sqrt(x*x + y*y));
		} while (next_permutation(b, b + n));
		printf("%lf\n", answer);
	}
	return 0;
}