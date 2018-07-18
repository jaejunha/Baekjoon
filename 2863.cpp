#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;
double s[4];
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	s[0] = (double)a / c + (double)b / d;
	s[1] = (double)c / d + (double)a / b;
	s[2] = (double)d / b + (double)c / a;
	s[3] = (double)b / a + (double)d / c;
	double p[4];
	for (int i = 0; i < 4; i++)
		p[i] = s[i];
	sort(p, p + 4);
	double m = p[3];
	for (int i = 0; i < 4; i++) {
		if (s[i] == m) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}