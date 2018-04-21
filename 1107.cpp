#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int k;

int m;
int a[10];

int main() {
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0, j; i < k; i++) {
		scanf("%d", &j);
		a[j] = 1;
	}

	m = abs(100 - n);
	if (k == 10) {
		printf("%d", m);
		return 0;
	}

	for (int i = 0, t; i <= 1000000; i++) {
		t = abs(i - n);
		for (int j = i; j > 0; j /= 10) {
			if (a[j % 10]) {
				t = 1000001;
				break;
			}
			t++;
		}
		if (i == 0) {
			for (int j = 0; j < 10; j++) {
				if (!a[j]) {
					t++;
					break;
				}
				t++;
			}
		}
		m = min(m, t);
	}

	printf("%d", m);
	return 0;
}