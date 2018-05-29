#include <stdio.h>

int t;
int l;
long long n, m, s;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n == 0) printf("0\n");
		else {
			for (l = 0, m = n; m; l++, m /= 10);
			for (s = 1; l--; s *= 10);
			if (n >= s / 2 - 1)
				printf("%lld\n", (s / 2 - 1)*(s / 2));
			else
				printf("%lld\n", (s - 1 - n)*n);
		}
	}
	return 0;
}