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

const int MAXN = (100000) + 10;

int N, Q;
int arr[MAXN];
LL tree[MAXN << 2];
LL lazy[MAXN << 2];

void build(int lo = 1 , int hi = N , int node = 1) {
	if(lo == hi) {tree[node] = 0, lazy[node] = 0; return ;}
	mlr ; build(lo , mid , l) , build(mid + 1 , hi , r);
	tree[node] = tree[l] + tree[r], lazy[node] = lazy[l] + lazy[r];
}

void update(int x, int y, int value, int lo = 1 , int hi = N , int node = 1) {
	mlr;
	if(lazy[node]) {
		tree[node] += (LL)lazy[node] * (hi - lo + 1);
		if(lo != hi) lazy[l] += lazy[node] , lazy[r] += lazy[node];
		lazy[node] = 0; 
	} if(lo > hi or lo > y or hi < x) return;
	if(x <= lo and y >= hi) {
		tree[node] += (LL)value * (hi - lo + 1);
		if(lo != hi) lazy[l] += value , lazy[r] += value; return ;
	} update(x , y , value, lo , mid , l) , update(x , y , value , mid + 1 , hi , r);
	tree[node] = tree[l] + tree[r];
}

LL get(int x , int y, int lo = 1 , int hi = N , int node = 1) {
	mlr;
	if(lazy[node]) {
		tree[node] += (LL)lazy[node] * (hi - lo + 1);
		if(lo != hi) lazy[l] += lazy[node] , lazy[r] += lazy[node];
		lazy[node] = 0; 
	} if(lo > hi or lo > y or hi < x) return 0LL;
	if(x <= lo and y >= hi) return tree[node];
	return get(x , y ,lo , mid , l) + get(x , y , mid + 1 , hi , r);
} 

int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif
    	int test;
    	si(test);
    	while(test--) {
    		sii(N , Q);
	    	build();
	    	FOR(i , Q) {
	    		int a , b , c , d;
	    		siii(a , b , c);
	    		if(a) {
	    			printf("%lld\n",get(b,c));
	    		}	else {
	    			si(d);
	    			update(b , c , d);
	    		}
	    	}
    	}
}
