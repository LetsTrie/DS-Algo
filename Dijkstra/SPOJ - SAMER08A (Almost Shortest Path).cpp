#include<bits/stdc++.h>

#define fi first
#define endl '\n'
#define se second
#define LL long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define mod 1000000007
#define EPS (double)1e-8
#define pii pair<int , int>
#define sz(x) (int) x.size()
#define sl(x) scanf("%lld",&x)
#define sll(x, y) sl(x) , sl(y)
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

//int fx[] = {1 , 0 , -1 , 0, 1 , 1 , -1 , -1};
//int fy[] = {0 , 1 , 0 , -1, 1 , -1 , 1 , -1};

const int MAXN = 500 + 1;
const int inf = (int) 1e9;

int dis[MAXN];
int rdis[MAXN];
int ver , eg , sink , src;
vector<pii> G[MAXN], RG[MAXN];
int adj[MAXN][MAXN];
vector<pair<int , pii> > gr;

priority_queue<pii> pq;

inline void dj1(int s) {
	FOR(i , ver) dis[i] = inf;
	dis[s] = 0;
	pq.push({0 , s});
	while(!pq.empty()) {
		int u = pq.top().se;
		pq.pop();
		for(int i = 0 ; i < G[u].size() ; i++) {
			int v = G[u][i].fi;
			int w = G[u][i].se;
			if(dis[u] + w < dis[v]) {
				if(!adj[u][v]) continue;
				dis[v] = dis[u] + w;
				pq.push({-dis[v] , v});
			}
		}
	}
}

inline void dj2(int s) {
	FOR(i , ver) rdis[i] = inf;
	rdis[s] = 0;
	pq.push({0 , s});
	while(!pq.empty()) {
		int u = pq.top().se;
		pq.pop();
		for(int i = 0 ; i < RG[u].size() ; i++) {
			int v = RG[u][i].fi;
			int w = RG[u][i].se;
			if(rdis[u] + w < rdis[v]) {
				rdis[v] = rdis[u] + w;
				pq.push({-rdis[v] , v});
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif
    	while(sii(ver ,  eg) && (ver + eg) ) {
    		sii(src , sink);
    		FOR1(i , eg) {
    			int x , y , z;
    			siii(x , y , z);
    			adj[x][y] = z;
    			RG[y].pb({x , z});
    			G[x].pb({y , z});
    			gr.pb({x , {y , z}});
    		}

    		dj1(src);

    		dj2(sink);

    		FOR(i , eg) {
    			int u = gr[i].fi;
    			int v = gr[i].se.fi;
    			int w = gr[i].se.se;

    			if(dis[u] + w + rdis[v] == dis[sink]) {
    				adj[u][v] = 0;
    			} 
    		}

    		dj1(src);

    		printf("%d\n",  dis[sink] == inf ? -1 : dis[sink]);

    		FOR(i , ver) {
    			FOR(j , (int) G[i].size()) adj[i][ G[i][j].fi ] = 0;
    		}

    		FOR(i , ver) G[i].clear() , RG[i].clear(); 
    		gr.clear();
    	}
}
