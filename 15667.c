#include <stdio.h>
#include <math.h>

	int n;

  int main() {

	  scanf("%d", &n);
	  for (int i = sqrt(n); ; i++) {
		  if ((i*i + i + 1) == n) {
			  printf("%d", i);
			  return 0;
		  }
	  }
	  return 0;
  }