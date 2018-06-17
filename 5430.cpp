/* reference: http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220613867339&parentCategoryNo=&categoryNo=303&viewDate=&isShowPopularPosts=false&from=postView */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, s;
char com[100001];
char t;
bool r, e;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		deque<int> d;
		r = e = false;
		scanf("%s%d\n[", com, &m);

		s = 0;
		while (1) {
			t = getchar();
			if (t >= '0' && t <= '9') s = s * 10 + t - '0';
			else {
				if (s > 0) 
					d.push_back(s);
				s = 0;
				if (t == ']') 
					break;
			}
		}

		for (int j = 0; com[j]; j++) {
			if (com[j] == 'D') {
				if (d.empty()) {
					printf("error\n");
					e = true;
					break;
				}
				r ? d.pop_back() : d.pop_front();
			}
			else
				r = !r;
		}
		if (!e) {
			if (r)
				reverse(d.begin(), d.end());
			printf("[");
			for (int i = 0, s = d.size(); i < s; i++) {
				if (i != s - 1)
					printf("%d,", d[i]);
				else
					printf("%d", d[i]);
			}
			printf("]\n");
		}
	}
	return 0;
}