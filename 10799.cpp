#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<int> s;
char c[100001];
int answer;

int main() {
	scanf("%s", c);
	for (int i = 0, l = strlen(c); i < l; i++) {
		if (c[i] == '(')
			s.push(1);
		else {
			s.pop();
			if (i && c[i - 1] == ')')
				answer++;
			else
				answer += s.size();
		}
	}

	printf("%d", answer);
	return 0;
}