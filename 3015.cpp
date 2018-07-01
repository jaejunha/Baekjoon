/* reference: https://www.slideshare.net/Baekjoon/baekjoon-online-judge-3015 */
#include <cstdio>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> s;
long long a;

int main() {
	scanf("%d", &n);
	for (int i = 0, j, h; i < n; i++) {
		scanf("%d", &j);
		h = 1;
		if (s.empty())
			s.push({ j,h });
		else {
			while (!s.empty() && s.top().first <= j) {
				a += s.top().second;
				if (s.top().first == j)
					h += s.top().second;
				s.pop();
			}
			s.push({ j, h });
			if (s.size()>1)
				a++;
		}
	}
	printf("%lld", a);
	return 0;
}