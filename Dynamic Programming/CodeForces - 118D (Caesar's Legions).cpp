#include<bits/stdc++.h>

#define fin  freopen("input.txt", "r", stdin);
#define fout freopen("output.txt", "w", stdout);

#define fi first
#define endl '\n'
#define se second
#define LL long long
#define pb push_back
#define vi vector<int>
#define EPS (double)1e-8
#define pii pair<int , int>
#define sz(x) (int) x.size()
#define sl(x) scanf("%lld",&x)
#define sii(x, y) si(x) , si(y)
#define all(x) (x).begin() , (x).end()
#define lg2(X) (31 - __builtin_clz(X))
#define llg2(X) (63 - __builtin_clzll(X))
#define rall(x) (x).rbegin() , (x).rend()
#define siii(x, y, z) si(x) , si(y) , si(z)
#define mem(a , b) memset((a), (b), sizeof(a))
#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOR1(i , n) for(int i = 1 ; i <= n ; i++)
#define _ceil(n, a) ((n)%(a)==0?((n)/(a)):((n)/(a)+1))
#define mlr int mid = (lo + hi) / 2 , l = node << 1 , r = l | 1 // 1 based
#define itr(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
template <typename T> T si(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}

using namespace std;

const int MAXN = 22;
const int MOD  = 100000000;
/*
int fx[] = {1 , 0 , -1 , 0}; //, 1 , 1 , -1 , -1};
int fy[] = {0 , 1 , 0 , -1}; //, 1 , -1 , 1 , -1};
*/

int n1 , n2 , k1 , k2;
int DP[101][101][11][11];

int solve(int a , int b , int c, int d) {
	if(a == 0 && b == 0) return 1;
	if(DP[a][b][c][d] != -1) return DP[a][b][c][d];
	int ret1 = 0 , ret2 = 0;
	if(a - 1 >= 0 && c + 1 <= k1) ret1 = solve(a - 1 , b, c + 1, 0);
	if(b - 1 >= 0 && d + 1 <= k2) ret2 = solve(a , b - 1, 0 , d + 1);
	return DP[a][b][c][d] = (ret1 + ret2) % MOD;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	mem(DP , -1);
	sii(n1 , n2);
	sii(k1 , k2);
	printf("%d\n", solve(n1 , n2 , 0 , 0) % MOD);

}
