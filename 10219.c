#include <stdio.h>

int n;
int w, h;

char t;
char a[12][12];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h, &w);
		for (int j = 0; j < h; j++) {
			scanf("%c", &t);
			for (int k = 0; k < w; k++)
				scanf("%c", &a[j][k]);
		}
		scanf("%c", &t);
		for (int j = h - 1; j >= 0; j--) {
			for (int k = 0; k < w; k++)
				printf("%c", a[j][k]);
			printf("\n");
		}
	}

	return 0;
}