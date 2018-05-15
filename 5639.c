#include <stdio.h>
#include <stdlib.h>

struct Node {
	int v;
	Node *l;
	Node *r;
};

void print(Node *p) {
	if (p == NULL)
		return;
	print(p->l);
	print(p->r);
	printf("%d\n", p->v);
}

int main() {
	int n;
	int init = 0;
	Node *root;
	Node *p, *q;
	scanf("%d", &n);
	root = (Node*)malloc(sizeof(Node));
	root->v = n;
	root->l = root->r = NULL;
	while (scanf("%d", &n) == 1) {
		p = root;
		while (1) {
			if (p->v < n) {
				if (p->r != NULL)
					p = p->r;
				else {
					q = (Node*)malloc(sizeof(Node));
					q->v = n;
					q->l = q->r = NULL;
					p->r = q;
					break;
				}
			}
			else {
				if (p->l != NULL)
					p = p->l;
				else {
					q = (Node*)malloc(sizeof(Node));
					q->v = n;
					q->l = q->r = NULL;
					p->l = q;
					break;
				}
			}
		}
	}
	print(root);
	return 0;
}