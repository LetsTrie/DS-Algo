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
vector<pii> BCC[MAXN];
int idx;
stack<pii> st;

void Bcomp(int u , int par = -1) {
	vis[u] = 1;
	low[u] = dis[u] = ++timer;
	int child = 0;
	FOR(i , (int) G[u].size()) {
		int v = G[u][i];
		if(v == par) continue;
		if(!vis[v]) {
			child++;
			st.push(pii(u , v));
			Bcomp(v , u);
			low[u] = (low[u] > low[v]) ? low[v] : low[u];
			if((par != -1 && dis[u] <= low[v]) || (par == -1 && child > 1)) {
				while( !(st.top().fi == u && st.top().se == v) ) {
					BCC[idx].pb(pii(st.top().fi , st.top().se));
					st.pop();
				} 
				BCC[idx++].pb(pii(st.top().fi , st.top().se));
				st.pop();
			}
		} else if(dis[u] > dis[v]) {
			st.push(pii(u , v));
			low[u] = (low[u] > dis[v]) ? dis[v] : low[u];
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

    FOR(i , vertex) {
    	if(!vis[i]) {
    		Bcomp(i);
    		bool checker = 0;
    		while(!st.empty()) {
    			BCC[idx].pb(pii(st.top().fi , st.top().se));
				st.pop(); checker = 1;
    		}
    		if(checker) idx++;
    	}
    }
    
    FOR(i , idx) {
    	printf("%dth Component is:\n", i + 1);
    	FOR(j , (int) BCC[i].size()) {
    		printf("%d %d\n", BCC[i][j].fi , BCC[i][j].se);
    	}
    }
}
