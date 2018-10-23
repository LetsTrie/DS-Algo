#include<bits/stdc++.h>

#define fi first
#define se second
#define MAXN 500005
#define pb push_back
#define pii pair<int,int> 

#define FOR(i , n)  for(int i = 0 ; i < n  ; i++)
#define FOR1(i , n) for(int i = 1 ; i <= n ; i++)

template <typename T> T si(T &n){n = 0;bool negative = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') negative = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(negative) n = ~(n-1);return n;}
#define sii(x , y) si(x), si(y)
#define siii(x , y , z) si(x) , si(y) , si(z) 

using namespace std;

vector<int> G[MAXN];
bool vis[MAXN];
int low[MAXN] , dis[MAXN];
int timer;
set<pii> st;

void FindingBridge(int u , int par = -1) {
	vis[u] = 1;
	dis[u] = low[u] = ++timer; // Initially Discovery Time && Low Time are equal
	FOR(i , (int) G[u].size()) {
		int v = G[u][i];
		if(v == par) continue; // v -> u
		if(!vis[v]) {	
			FindingBridge(v , u);
			low[u] = (low[u] > low[v]) ? low[v] : low[u];
			if(dis[u] < low[v]) st.insert(pii(u , v));
		} 
		else if(dis[v] < dis[u]) { // Already Visited 		
			low[u] = (dis[v] < low[u]) ? dis[v] : low[u];
		}
	}
}
int main()
{   
    int vertex , edge;
    sii(vertex , edge);

    FOR(i , edge) {
    	int x , y;
    	sii(x , y);
    	G[x].pb(y);
    	G[y].pb(x);
    }

    FOR1(i , vertex) if(!vis[i]) FindingBridge(i);

    printf("Number of Bridges : %d.\n", (int) st.size());
    for(pii x : st) printf("%d %d\n", x.fi , x.se);
}


/*
8 9
1 2
1 3
2 4
3 4
4 5
5 6 
5 7
6 8
7 8
*/
