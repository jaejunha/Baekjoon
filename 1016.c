#include <stdio.h>

long long a[1000001];

int main() {
	int c = 0;
	long long mn, mx;
	scanf("%lld %lld", &mn, &mx);

	for (long long i = 2, x, s; i*i <= mx; i++) {
		s = i * i;
		x = mn / s;
		if ((mn % s) != 0)
			x++;

		for (long long j = x * s; j <= mx; j += s)
			a[j - mn] = 1;
	}

	for (long long i = mn; i <= mx; i++) {
		if (!a[i - mn])
			c++;
	}


	printf("%d", c);
	return 0;
}