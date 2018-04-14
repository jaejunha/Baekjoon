#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int n, k;
char temp[21];
char type[21];
int sum;
map<string, int> m;
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		m.clear();
		sum = 1;
		for (int j = 0; j < k; j++) {
			scanf("%s %s", temp, type);
			m[type] ++;
		}
		for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
			sum *= ((*i).second + 1);
		printf("%d\n", sum - 1);
	}

	return 0;
}