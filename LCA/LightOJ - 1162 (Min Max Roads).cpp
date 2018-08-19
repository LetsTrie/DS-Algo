
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

const int MAXN = 100005;
int par[MAXN];
vector<pii>G[MAXN];
int depth[MAXN];
bool vis[MAXN];
int Table[MAXN][22];
int TableMax[MAXN][22];
int TableMin[MAXN][22];
int Max[MAXN];
int Min[MAXN];
int ver;
int Log[MAXN];
int two[22];

void Clear() {
	FOR1(i , ver) {
		G[i].clear();
		depth[i] = 0;
		vis[i] = 0;
		par[i] = -1;
		FOR(j , 21)Table[i][j] = -1;
		FOR(j , 21)TableMax[i][j] = INT_MIN;
		FOR(j , 21)TableMin[i][j] = INT_MAX;
		Max[i] = INT_MIN;
		Min[i] = INT_MAX;
	}
}


void dfs(int u = 1 , int d = 1) {
	vis[u] = 1 , 
	depth[u] = d;
	for(int i = 0 ; i < G[u].size();  i++) {
		int v = G[u][i].fi;
		int w = G[u][i].se;
		if(!vis[v]) {
			par[v] = u;
			Max[v] = Min[v] = w;
			dfs(v , d + 1);
		}
	}
}

void lca() {
	FOR1(i , ver) Table[i][0] = par[i], TableMax[i][0] = Max[i] , TableMin[i][0] = Min[i];
	for(int i = 1 ; two[i] <= ver ; i++) {
		for(int j = 1 ; j <= ver ; j++) {
			if(Table[j][i - 1] != -1) {
				Table[j][i] = Table[ Table[j][i-1] ][i-1];
				TableMax[j][i] = max(TableMax[j][i-1] , TableMax[ Table[j][i-1] ][i-1]);
				TableMin[j][i] = min(TableMin[j][i-1] , TableMin[ Table[j][i-1] ][i-1]);
			}
		}
	}
}

pii query(int x , int y) {
	int mn = INT_MAX;
	int mx = INT_MIN;
	if(x == y) return pii(0, 0);
	int T;
	if(depth[x] < depth[y]) T = x , x = y , y = T; 
	for(int i = 21 ; i >= 0 ; i--) {
		if(depth[x] - two[i] >= depth[y]) {
			mn = min(mn , TableMin[x][i]);
			mx = max(mx , TableMax[x][i]);
			x = Table[x][i];
		}
	}
	if(x == y) return pii(mn , mx);
	for(int i = 21 ; i >= 0 ; i--) {
		if(Table[x][i] != Table[y][i] && Table[x][i] != -1) {
			mn = min(mn , TableMin[x][i]);  mn = min(mn , TableMin[y][i]);
			mx = max(mx , TableMax[x][i]);	mx = max(mx , TableMax[y][i]);		
			x = Table[x][i] , y = Table[y][i];
		}
	}
	mn = min(mn , Min[x]) , mn = min(mn , Min[y]);
	mx = max(mx , Max[x]) , mx = max(mx , Max[y]);
	return pii(mn , mx);
}

int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
#endif
    	Log[1] = 0, two[0] = 1;
    	for(int i = 2 ; i < MAXN ; i++) Log[i] = Log[ i >> 1 ] + 1;
    	for(int i = 1 ; i <= 21 ; i++) two[i] = two[i - 1] << 1;
    	int test;
    	si(test);
    	while(test--) {
		    	si(ver); ver--;
		    	FOR(i , ver) {
		    		int x , y, z;
		    		siii(x , y , z);
		    		G[x].pb({y , z});
		    		G[y].pb({x , z});
		    	} ver++;
		    	FOR1(i , ver) par[i] = -1, Max[i] = INT_MIN, Min[i] = INT_MAX;
		    	dfs(); 
		    	lca();
		    	int Q;
		    	si(Q);
		    	static int ks = 1;
		    	printf("Case %d:\n",ks++);
		    	while(Q--) {
		    		int x , y;
		    		sii(x , y);
		    		pii ans = query(x , y);
		    		printf("%d %d\n", ans.fi , ans.se);
		    	}
		    	Clear();
		}
}
