#include<bits/stdc++.h>

#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)

#define fi first
#define endl '\n'
#define se second
#define MAXN 500005
#define inf INT_MAX // Be CareFul About The OverFlow
#define LL long long
#define pb push_back
#define mp make_pair
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
#define mlr int mid = (lo + hi) / 2 , l = node << 1 , r = l | 1
#define itr(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
template <typename T> T si(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}

using namespace std;

int fx[] = {1 , 0 , -1 , 0 , 1 , 1 , -1 , -1};
int fy[] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};

int N , K;
char str[MAXN];
int tree[MAXN];

void build(int F , int lo = 1, int hi = N , int node = 1) {
	if(lo == hi) {
		if(F == 1)tree[node] = (str[lo - 1] == 'a') ;
		else tree[node] = (str[lo - 1] == 'b');
		return;
	}
	mlr ; build(F , lo , mid , l) , build(F , mid + 1 , hi , r);
	tree[node] = tree[l] + tree[r];
}

LL get(int x , int y , int lo = 1, int hi = N , int node = 1){
	if(lo > hi || lo > y || hi < x) return 0LL;
	if(x <= lo && hi <= y) return tree[node]; mlr ;
	return get(x , y , lo , mid , l) + get(x , y , mid + 1 , hi, r);
}


int main()
{
	sii(N , K);
	scanf(" %s", str);
	int mx = 1;
	FOR1(itr , 2) {
		build(itr);
		int lo = 0 , hi = 0;
		while(hi < N){
			while(hi < N && lo <= hi && get(lo + 1 , hi + 1) <= K) {
				mx = max(mx , hi - lo + 1);
				hi++;
			}
			while(lo < N && lo <= hi && get(lo + 1 , hi + 1) > K) {
				lo++;
			}
			while(lo > hi) hi++; 
		}
	}
	printf("%d\n",mx);
}
