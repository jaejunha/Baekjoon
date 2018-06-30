#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, k; 
long long dp[29][29]; 
long long c(int n, int r) { 
	long long &ret = dp[n][r]; 
	if (ret) 
		return ret; 
	ret = c(n - 1, r - 1) + c(n - 1, r); 
	return ret; 
}
int main() { 
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 1, j = n + m - 2; i <= j; i++) { 
		dp[i][i] = dp[i][0] = 1; 
		dp[i][1] = dp[i][i - 1] = i; 
	}if (k) { 
		int i = (k - 1) / m; 
		int j = (k - 1) % m; 
		printf("%lld", c(i + j, min(i, j))*c(n + m - i - j - 2, min(n - i - 1, m - j - 1))); 
	} else 
		printf("%lld", c(n + m - 2, min(n - 1, m - 1))); 
	return 0; 
}