#include <stdio.h>

int ix[27];
char tree[67108864];

void pre(int i) {
	printf("%c", tree[i]);
	if (tree[2 * i])
		pre(2 * i);
	if (tree[2 * i + 1])
		pre(2 * i + 1);
}
void in(int i) {
	if (tree[2 * i])
		in(2 * i);
	printf("%c", tree[i]);
	if (tree[2 * i + 1])
		in(2 * i + 1);
}
void post(int i) {
	if (tree[2 * i])
		post(2 * i);
	if (tree[2 * i + 1])
		post(2 * i + 1);
	printf("%c", tree[i]);
}

int main() {
	int n;
	char a, b, c;
	tree[1] = 'A';
	ix[1] = 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &a);
		scanf("%c %c %c", &a, &b, &c);
		if (b != '.') {
			ix[b - 'A' + 1] = 2 * ix[a - 'A' + 1];
			tree[ix[b - 'A' + 1]] = b;
		}
		if (c != '.') {
			ix[c - 'A' + 1] = 2 * ix[a - 'A' + 1] + 1;
			tree[ix[c - 'A' + 1]] = c;
		}
	}

	pre(1);
	printf("\n");
	in(1);
	printf("\n");
	post(1);

	return 0;
}