Some Classical Dynamic Programming Problems :

1) Calculating Fibonacci Number :
--------------------------------------------------------------

int solve(int n) {
	if(n == 1 || n == 0) return n;
	if(Fib[n] != -1) return Fib[n];
	return Fib[n] = solve(n - 1) + solve(n - 2); 
}

2) Calculating nCr : 
--------------------------------------------------------------

int solve(int n , int r) { // n >= r
	if(n == r || r == 0) return 1;
	if(nCr[n][r] != -1) return nCr[n][r];
	return nCr[n][r] = solve(n - 1 , r) + solve(n - 1 , r - 1);
}

3) 0-1 Knapsack : 
--------------------------------------------------------------

int solve(int i , int cap) {
    	if(i == N) return 0;
    	if(knap[i][cap] != -1) return knap[i][cap]; 
	LL ans1 = 0 , ans2 = 0;
	if(cap - weight[i] >= 0) ans1 =price[i] + solve(i + 1 , cap - weight[i]);
	ans2 = solve(i + 1 , cap); 
	return knap[i][cap] = max(ans1 , ans2);
}

4) Coin Change : 
--------------------------------------------------------------

LL solve(int i , int make) { // No of Ways
	if(i == 5) return (make == 0);
	if(DP[i][make] != -1) return DP[i][make];
	LL ret1 = 0 , ret2 = 0;
	if(make - arr[i] >= 0) ret1 = solve(i , make - arr[i]);
	ret2 = solve(i + 1 , make);
	return DP[i][make] = ret1 + ret2;
}

5) Longest Common Subsequence : 
--------------------------------------------------------------

int solve(int i , int j) {
	if(str1[i] == '\0' || str2[j] == '\0') return 0;
	if(DP[i][j] != -1) return DP[i][j]; int ret;
	if(str1[i] == str2[j]) ret = 1 + solve(i + 1 , j + 1);
	else ret = max(solve(i + 1, j) , solve(i , j + 1));
	return DP[i][j] = ret;
}
