Some Classical Dynamic Programming Problems :

1) Calculating Fibonacci Number :
----------------------------------------
int Fib[30];

int solve(int n) {
	if(n == 1 || n == 0) return n;
	if(Fib[n] != -1) return Fib[n];
	return Fib[n] = solve(n - 1) + solve(n - 2); 
}

int main() {
	mem(Fib, -1);
	cout << solve(30) << endl;
}

2) Calculating nCr : 
----------------------------------------

int nCr[101][101];

int solve(int n , int r) { // n >= r
	if(n == r || r == 0) return 1;
	if(nCr[n][r] != -1) return nCr[n][r];
	return nCr[n][r] = solve(n - 1 , r) + solve(n - 1 , r - 1);
}

int main() {
	mem(nCr , -1);
	cout << solve(5 , 3) << endl;
}

3) 0-1 Knapsack : 
----------------------------------------
