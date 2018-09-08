/* reference: http://hsp1116.tistory.com/12 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int t, n;
vector<P> v;

int main() {
	int x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		int s = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());
		int min = v[0].second;
		for (int i = 0; i < n; i++) {
			if (min > v[i].second) {
				s++;
				min = v[i].second;
			}
		}
		cout << s + 1 << endl;
	}
	return 0;
}