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
