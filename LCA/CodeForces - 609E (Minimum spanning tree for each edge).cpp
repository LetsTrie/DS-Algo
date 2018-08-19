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

const int MAXN = 200005;
int par[MAXN];
vector<pii>G[MAXN];
int depth[MAXN];
bool vis[MAXN];
int Table[MAXN][22];
int TableMax[MAXN][22];
int ver, eg;
int Log[MAXN];
int two[22];
int T;
vector<pair<int , pii> >mst;
vector<pair<int , pii> >dntsort;
LL best;

int rep(int  x)  {
	if(x == par[x]) return x;
	return par[x] = rep(par[x]);
} 

void Clear() {
	FOR1(i , ver) {
		depth[i] = 0;
		vis[i] = 0;
		par[i] = -1;
		FOR(j , 21)Table[i][j] = -1;
		FOR(j , 21)TableMax[i][j] = INT_MIN;
	}
}


void dfs(int u = 1 , int d = 1) {
	vis[u] = 1 , 
	depth[u] = d;
	for(int i = 0 ; i < G[u].size();  i++) {
		int v = G[u][i].fi;
		int w = G[u][i].se;
		if(!vis[v]) {
			Table[v][0] = u;
			TableMax[v][0] = w;
			dfs(v , d + 1);
		}
	}
}

void lca() {
	for(int i = 1 ; two[i] <= ver ; i++) {
		for(int j = 1 ; j <= ver ; j++) {
			if(Table[j][i - 1] != -1) {
				Table[j][i] = Table[ Table[j][i-1] ][i-1];
				TableMax[j][i] = max(TableMax[j][i-1] , TableMax[ Table[j][i-1] ][i-1]);
			}
		}
	}
}

LL query(int x , int y) {
	LL mx = LLONG_MIN;
	if(x == y) return 0;
	if(depth[x] < depth[y]) T = x , x = y , y = T; 
	for(int i = 21 ; i >= 0 ; i--) {
		if(depth[x] - two[i] >= depth[y]) {
			mx = max(mx , 1LL * TableMax[x][i]);
			x = Table[x][i];
		}
	}
	if(x == y) return mx;
	for(int i = 21 ; i >= 0 ; i--) {
		if(Table[x][i] != Table[y][i] && Table[x][i] != -1) {
			mx = max(mx , 1LL * TableMax[x][i]);	mx = max(mx , 1LL * TableMax[y][i]);		
			x = Table[x][i] , y = Table[y][i];
		}
	}
	mx = max(mx , 1LL * TableMax[x][0]) , mx = max(mx , 1LL * TableMax[y][0]);
	return mx;
}


int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif

    	Log[1] = 0, two[0] = 1;
    	for(int i = 2 ; i < MAXN ; i++) Log[i] = Log[ i >> 1 ] + 1;
    	for(int i = 1 ; i <= 21 ; i++) two[i] = two[i - 1] << 1;

    	Clear();

    	sii(ver , eg);
    	FOR(i , eg) {
    		int x , y , z;
    		siii(x , y , z);
    		mst.pb({z , {x , y}});
    		dntsort.pb({z , {x , y}});
    	}

    	sort(all(mst));
    	LL w = 0;
    	FOR1(i , ver) par[i] = i;
    	FOR(i , eg) {

    		auto uu = mst[i];
    		int u = uu.se.fi;
    		int v = uu.se.se;
    		int w = uu.fi;

    		int ru = rep(u) , rv = rep(v);

    		if(ru != rv) {
    			if(ru < rv) T = ru , ru = rv , rv = T;
    			par[ru] = rv;
    			G[u].pb({v , w});
    			G[v].pb({u , w});
    			best += w;
    		}
    	}

    	dfs(); lca();

    	FOR(i , eg) {
    		int u = dntsort[i].se.fi;
    		int v = dntsort[i].se.se;
    		int w = dntsort[i].fi;
    		printf("%lld\n", best - query(u , v) + w);
    	}
}
