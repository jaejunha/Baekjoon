/* reference: http://deque.tistory.com/80 */
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char temp[5001];
vector<string> v;
string t;
int length;
int pi[5000][5000];
int m;

int main() {
	scanf("%s", &temp);
	length = strlen(temp);
	for (int k = 0; k < length; k++)
		v.push_back(temp + k);

	for (int k = 0; k<length; k++) {
		t = v.at(k);
		for (int i = 1, j = 0, s = v.at(k).size(); i < s; i++) {
			while (j && t[i] != t[j])
				j = pi[k][j - 1];
			if (t[i] == t[j])
				pi[k][i] = ++j;
		}
		for (int i = 0, s = v.at(k).size(); i < s; i++)
			m = max(m, pi[k][i]);
	}
	printf("%d", m);
	return 0;
}