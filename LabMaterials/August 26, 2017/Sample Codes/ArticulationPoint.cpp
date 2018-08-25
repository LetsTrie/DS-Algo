#include<bits/stdc++.h>

#define fi first
#define se second
#define MAXN 500005
#define pb push_back

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
bool AP[MAXN];

void FindingAP(int u , int par = -1) {

	vis[u] = 1;

	dis[u] = low[u] = ++timer; // Initially Discovery Times && Low Times are equal

	int child = 0;

	FOR(i , G[u].size()) {
		
		int v = G[u][i];
		
		if(v == par) continue; // v -> u
		
		if(!vis[v]) {

			++child; //Actual Child which Creates Different SubTree		
			
			FindingAP(v , u);
		
			low[u] = (low[u] > low[v]) ? low[v] : low[u];
		
			if(par != -1 && dis[u] <= low[v]) AP[u] = 1;
		
		} 

		else if(dis[v] < low[u]) { // Already Visited 
		
			low[u] = dis[v];
		}
	}

	if(par == -1 and child > 1) { // Special Root Check

		AP[u] = 1;

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

    FOR1(i , vertex) if(!vis[i]) FindingAP(i);

    int counter = 0;
    FOR1(i , vertex) if(AP[i]) ++counter;
    printf("Number Of Articulation Point is %d.\n", counter);
    printf("Those Are:");
    FOR1(i , vertex) if(AP[i]) printf(" %d", i);
    printf("\n");
}


/*

7 6
1 2
2 3
1 4 
4 5
1 6 
6 7

*/
