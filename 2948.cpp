#include <iostream>
using namespace std;

int d, m, s;
char week[][20] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };
int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	scanf("%d%d", &d, &m);
	if (m == 1)
		printf("%s", week[d % 7]);
	else {
		for (int i = 1; i < m; i++)
			s += day[i - 1];
		s += d;
		printf("%s", week[s % 7]);
	}

	return 0;
}