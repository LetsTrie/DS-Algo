#include<bits/stdc++.h>

#define fi first
#define endl '\n'
#define se second
#define LL long long
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define EPS (double)1e-8
#define pii pair<int , int>
#define sz(x) (int) x.size()
#define sl(x) scanf("%lld",&x)
#define sii(x, y) si(x) , si(y)
#define all(x) (x).begin() , (x).end()
#define lg2(X) (31 - __builtin_clz(X))
#define Min(a , b) ( (a < b) ? a : b )
#define Max(a , b) ( (a < b) ? b : a )
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

 int fx[] = {1 , 0 , -1 , 0}; //, 1 , 1 , -1 , -1};
 int fy[] = {0 , 1 , 0 , -1}; //, 1 , -1 , 1 , -1};

#define MAXN 1000000
int ans[MAXN + 10];
int sum[MAXN + 10][10];

int ret(int x) {
	if(x >= 0 && x <= 9) return x;
	int pro = 1;
	while(x) {
		int MOD = x % 10;
		if(MOD) pro *= MOD;
		x /= 10;
	}
	return ret(pro);
}



int main()
{
	//freopen("in.txt","r", stdin);
	
	FOR1(i , MAXN) {
	 	ans[i] = ret(i);
	}

	FOR1(i , MAXN) {
		FOR1(j , 9) {
			sum[i][j] = sum[i - 1][j] + (ans[i] == j);
		}
	}

	int q;
	si(q);
	while(q--) {
		int x , y , z;
		siii(x , y , z);

		printf("%d\n", sum[y][z] - sum[x - 1][z]);
	}

}
