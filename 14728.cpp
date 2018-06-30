/* reference: http://wookje.dance/2017/09/24/boj-14728-%EB%B2%BC%EB%9D%BD%EC%B9%98%EA%B8%B0/ */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, t, a[10001];
vector<pair<int, int>> v;

int main() {
	scanf("%d%d", &n, &t);
	v.resize(n);
	for (int i = 0; i < n; i++) 
		scanf("%d %d", &v[i].first, &v[i].second);
	
	for (int i = 0; i < n; i++)
		for (int j = t; j >= v[i].first; j--)
			a[j] = max(a[j], a[j - v[i].first] + v[i].second);
	printf("%d", a[t]);
	return 0;
}