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

/*
int fx[] = {1 , 0 , -1 , 0}; //, 1 , 1 , -1 , -1};
int fy[] = {0 , 1 , 0 , -1}; //, 1 , -1 , 1 , -1};
*/

const int MAXN = (1 << 17) + 10;

int ac, N, Q;
int arr[MAXN];
int tree[MAXN << 2];

void build(int lo = 1, int hi = N , int node = 1, int F = (ac & 1)) { // Draw The Graph For N when even and when N is odd
	/* Do U really Build */
	/* 1 Based. Be Careful */
	/* Tree size is 4 times MAXN */
	if(lo == hi) { tree[node] = arr[lo] ; return; }
	mlr ; build(lo , mid , l, F ^ 1) , build(mid + 1 , hi , r, F ^ 1);
	if(F) tree[node] = tree[l] | tree[r]; 
	else tree[node] = tree[l] ^ tree[r];
}


void update(int idx , int val , int lo = 1, int hi = N , int node = 1, int F = (ac & 1)) {
	if(lo > hi || idx < lo || hi < idx) return ;
	if(idx == hi && idx == lo) {tree[node] = val ; return ;}
	mlr ; update(idx , val , lo , mid , l, F ^ 1) , update(idx , val , mid + 1 , hi , r, F ^ 1);
	if(F) tree[node] = tree[l] | tree[r]; 
	else tree[node] = tree[l] ^ tree[r];
}

int get(int x , int y , int lo = 1, int hi = N , int node = 1, int F = (ac & 1)){
	if(lo > hi || lo > y || hi < x) return 0;
	if(x <= lo && hi <= y) return tree[node]; mlr ;
	LL X = get(x , y , lo , mid , l, F ^ 1);
	LL Y = get(x , y , mid + 1 , hi, r, F ^ 1);
	if(F) return X | Y; 
	else return X ^ Y;
}



int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif

    	sii(ac , Q);
    	N = 1 << ac;
    	FOR1(i , N) si(arr[i]) ; 
    	build();
    	FOR(i , Q) {
    		int x , y;
    		sii(x , y);
    		update(x , y);
    		printf("%d\n",tree[1]);
    	}
}
