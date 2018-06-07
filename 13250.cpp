#include <iostream>

using namespace std;

int n;
double a[1000001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0)
				a[i] += a[i - j] / 6;
		}
	}
	cout.precision(17);
	cout << a[n];
	return 0;
}