#include<bits/stdc++.h>

#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)

#define fi first
#define endl '\n'
#define se second
#define MAXN 10000004
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

int freq[MAXN];
bool vis[MAXN];
LL F[MAXN];

void siv() {
	for(int i = 2 ; i <= MAXN ; i += 2) {
		if(freq[i]) {
			F[2] += freq[i];
		} vis[i] = 1;
	}
	for(int i = 3 ; i <= MAXN ; i += 2) {
		if(!vis[i]) {
			for(int j = i ; j <= MAXN ; j += i) {
				if(freq[j]) {
					F[i] += freq[j];
				}vis[j] = 1;
			}
		}
	}
}

int main()
{
	int N;
	si(N); int X;
	FOR(i , N) si(X) , freq[X]++;
	siv();
	FOR1(i , 10000000) F[i] += F[i - 1];
	int q; si(q);
	while(q--) {
		int x , y;
		sii(x , y);
		x = Min(x , 10000000);
		y = Min(y , 10000000);
		printf("%lld\n", F[y] - F[x - 1]);
	}
}
