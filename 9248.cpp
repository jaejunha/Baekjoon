/* reference: http://deque.tistory.com/82 */
/* reference: http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=221028710658 */
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string str;
int length, d;
int t[500001], p[500000], s[500000], l[500000];

bool cmp(int i, int j) {
	if (p[i] != p[j])
		return p[i] < p[j];
	i += d;
	j += d;
	return (i < length && j < length) ? (p[i] < p[j]) : (i > j);
}

int main() {
	cin >> str;
	length = str.size();
	for (int i = 0; i < length; i++) {
		s[i] = i;
		p[i] = str.at(i);
	}

	for (d = 1;; d *= 2) {
		sort(s, s + length, cmp);

		for (int i = 1; i < length; i++)
			t[i] = t[i - 1] + cmp(s[i - 1], s[i]);

		for (int i = 0; i < length; i++)
			p[s[i]] = t[i];

		if (t[length - 1] == length - 1)
			break;
		memset(t, 0, sizeof(t));
	}

	for (int i = 0; i < length; i++)
		printf("%d ", s[i] + 1);
	printf("\nx ");

	for (int i = 0, k = 0; i< length; i++, k = max(k - 1, 0)) {
		if (p[i] == length - 1) continue;

		for (int j = s[p[i] + 1]; str[i + k] == str[j + k]; k++);
		l[p[i]] = k;
	}

	for (int i = 0; i < length - 1; i++)
		printf("%d ", l[i]);

	return 0;
}
