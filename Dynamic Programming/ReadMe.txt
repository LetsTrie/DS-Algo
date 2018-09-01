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
