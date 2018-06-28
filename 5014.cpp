#include <cstdio>
using namespace std;

int f, s, g, u, d;
bool v[1000001];

int main() {
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	if (s == g)
		printf("0");
	else if (s < g && u == 0)
		printf("use the stairs");
	else if (s > g && d == 0)
		printf("use the stairs");
	else {
		int c = 0;
		int n = s;
		while (n != g) {
			if (n > g) {
				if (n - d < g)
					n += u;
				else
					n -= d;
			}
			else {
				if (n + u > g)
					n -= d;
				else
					n += u;
			}
			if (v[n]) {
				printf("use the stairs");
				return 0;
			}
			v[n] = true;
			c++;
		}
		printf("%d", c);
	}
	return 0;
}