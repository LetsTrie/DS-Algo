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

const int MAXN = 200 + 10;

int T , par[MAXN];

vector<pair<int , pair<int , int> > > G;
vector<pair<int , pair<int , int> > > temp;

int rep(int x) {
	if(x == par[x]) return x;
	return par[x] = rep(par[x]);
}

void unite(int x , int y) {
	x = rep(x) , y = rep(y);
	if(x != y) {
		if(x < y) T = x , x = y , y = T;
		par[x] = y;
	}
}

int main()
{
	int test;
	int ks = 1;
	si(test);
	while(test--) {
		G.clear();
		temp.clear();
		int ver , eg;
		sii(ver , eg);
		printf("Case %d:\n",ks++);
		FOR(i , eg) {
			int x , y , z;
			siii(x , y , z);
			G.pb({z , {y , x}});
			FOR1(i , ver) par[i] = i; 
			LL sum = 0;
			sort(all(G));
			FOR(i , sz(G)) {
				int ww = G[i].fi;
				int vv = G[i].se.fi;
				int uu = G[i].se.se;
				if(rep(uu) != rep(vv)) {
					temp.pb({ww , {vv , uu}});
					unite(uu , vv);
					sum += ww;
				}
			}
			G.clear();
			FOR(i , sz(temp)) G.pb({temp[i].fi , {temp[i].se.fi,temp[i].se.se}});
			temp.clear();
			int check = 0;
			FOR1(i , ver) if(par[i] == i) check++;
			printf("%lld\n", (check == 1) ? sum : -1LL);
		}
	}
}
