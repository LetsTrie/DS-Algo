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

/********************* OverFlow ***********************/

const int MAXN = 10000;
const LL inf = 1000000000000LL;

struct info {
	LL dis;
	int x;
	info(){}
	info(LL _dis , int _x) : dis(_dis) , x(_x) {}
	bool operator < (const info &other) const {
		return dis > other.dis;
	}
};

LL dist[MAXN];
LL rdist[MAXN];
priority_queue<info> pq;
vector<pii> G[MAXN];
vector<pii> rev[MAXN];
int ver , eg , from , to , p;

void DJ1() {
	FOR1(i , ver) dist[i] = inf;
	dist[from] = 0;
	pq.push(info(dist[from], from));
	while(!pq.empty()) {
		int u = pq.top().x ;
		pq.pop();
		FOR(i , sz(G[u])) {
			int v = G[u][i].fi;
			int w = G[u][i].se;
			if(dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push(info(dist[v] + w , v));
			}
		}
	}
}

void DJ2() {
	FOR1(i , ver) rdist[i] = inf;
	rdist[to] = 0;
	pq.push(info(rdist[to], to));
	while(!pq.empty()) {
		int u = pq.top().x ;
		pq.pop();
		FOR(i , sz(rev[u])) {
			int v = rev[u][i].fi;
			int w = rev[u][i].se;
			if(rdist[u] + w < rdist[v]) {
				rdist[v] = rdist[u] + w;
				pq.push(info(rdist[v] + w , v));
			}
		}
	}
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
    		siii(ver , eg , from);
    		sii(to , p);
    		FOR(i , eg) {
    			int x , y , z;
    			siii(x , y , z);
    			G[x].pb({y , z});
    			rev[y].pb({x , z});
    		}
    		
    		DJ1() , DJ2();
    		int mx = -1;
    		FOR1(i , ver) {
    			FOR(j , sz(G[i])) {
    				int v = G[i][j].fi;
    				int w = G[i][j].se;

    				if(dist[i] + w + rdist[v] <= p) {
    					mx = max(mx , w);
    				}
    			}
    		}
    		printf("%d\n",mx);
    		FOR1(i , ver) {
    			G[i].clear() , rev[i].clear();
    		}
    	}
}
