#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

deque<int> d;

int n, m;
char com[100001];
char t;
bool r, e;
int l;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		d.clear();
		r = e = false;
		scanf("%s", com);
		getchar();
		scanf("%d", &m);
		getchar();
		if (m == 0)
			scanf("%c%c", &t, &t);
		else {
			scanf("%c", &t);
			for (int j = 0, p; j < m; j++) {
				scanf("%d%c", &p, &t);
				d.push_back(p);
			}
		}
		getchar();
		l = strlen(com);
		for (int j = 0; j < l; j++) {
			if (com[j] == 'D') {
				if (r) {
					if (d.size() > 0)
						d.pop_back();
					else {
						printf("error\n");
						e = true;
						break;
					}
				}
				else {
					if (d.size() > 0)
						d.pop_front();
					else {
						printf("error\n");
						e = true;
						break;
					}
				}
			}
			else {
				r = !r;
			}
		}
		if (!e) {
			if (r) {
				printf("[");
				int k = d.size() - 1;
				for (deque<int>::iterator iter = d.end() - 1; k >= 0; k--) {
					if (k != 0)
						printf("%d,", *iter);
					else
						printf("%d", *iter);
					if (k > 0)
						iter--;
				}
				printf("]\n");
			}
			else {
				printf("[");
				for (deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {
					if ((iter + 1) != d.end())
						printf("%d,", *iter);
					else
						printf("%d", *iter);
				}
				printf("]\n");
			}
		}
	}
	return 0;
}