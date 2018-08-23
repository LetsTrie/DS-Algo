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

const int MAXN = 10000 + 1;
LL D[MAXN];
int ver , eg , k , src , sink;
LL sudo[MAXN];
vector<pii> G[MAXN];
priority_queue<pair<LL , int> > pq; 
LL inf;

inline void DJ(int source)
{
	while(!pq.empty()) pq.pop();
    for(int i = 1; i <= ver ; i++) D[i] = inf;
    D[source] = 0;
    pq.push({-D[source],source});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i<G[u].size(); i++)
        {
            int Adj = G[u][i].first;
            int weight = G[u][i].second;
            if(D[Adj] > D[u] + weight)
            {
                D[Adj] = D[u] + weight;
                pq.push({-D[Adj],Adj});
            }
        }
    }
}

inline LL Check(int x , int y , int z) {
	while(!pq.empty()) pq.pop();
	if(D[x] + z < D[y]) sudo[y] = sudo[x] + z; pq.push({-sudo[y] , y});
	int T; T = x , x = y , y = T;
	if(D[x] + z < D[y]) sudo[y] = sudo[x] + z; pq.push({-sudo[y] , y});
	while(!pq.empty()) {
		int u = pq.top().second;
        pq.pop();
        if(u == sink) return sudo[u];
        for(int i = 0; i<G[u].size(); i++)
        {
            int Adj = G[u][i].first;
            int weight = G[u][i].second;
            if(sudo[Adj] > sudo[u] + weight)
            {
                sudo[Adj] = sudo[u] + weight;
                pq.push({-sudo[Adj],Adj});
            }
        }
	}
	return sudo[sink];
}

int main() {

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif

    	int test;
    	si(test);
    	inf = (LL) 1e18;
    	while(test--) {
    		siii(ver , eg , k);
    		sii(src , sink);
    		FOR(i , eg) {
    			int x , y , z;
    			siii(x , y , z);
    			G[x].pb({y , z});
    		}
    		DJ(src);

    		LL mn = D[sink];

    		while(k--) {
    			int x , y , z;
    			siii(x , y , z);
    			FOR1(i , ver) sudo[i] = D[i];
    			mn = min(mn , Check(x , y , z));
    		}

    		printf("%lld\n", mn == inf ? -1 : mn);
    		FOR1(i , ver) G[i].clear();
    	}
}
