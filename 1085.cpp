#include <cstdio>
#include <algorithm>
using namespace std;

int x, y, w, h;

int main() {
	scanf("%d%d%d%d", &x, &y, &w, &h);
	printf("%d", min(min(w - x, x), min(h - y, y)));
	return 0;
}