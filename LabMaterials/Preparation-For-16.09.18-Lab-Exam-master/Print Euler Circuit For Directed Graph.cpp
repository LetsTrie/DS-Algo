#include<bits/stdc++.h>

#define fi first
#define se second
#define MAXN 500005
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin() , (x).end() 

#define FOR(i , n)  for(int i = 0 ; i < n  ; i++)
#define FOR1(i , n) for(int i = 1 ; i <= n ; i++)

template <typename T> T si(T &n){n = 0;bool negative = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') negative = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(negative) n = ~(n-1);return n;}
#define sii(x , y) si(x), si(y)
#define siii(x , y , z) si(x) , si(y) , si(z) 

using namespace std;

vector<int> ans;
vector<int> G[MAXN];

void PrintEuler(int u = 0) {
	while(!G[u].empty()) {
		int v = G[u].back();
		G[u].pop_back();
		PrintEuler(v);
	}
	ans.pb(u);
}

int main()
{
	int vertex, edge;
	sii(vertex, edge);
	
	FOR(i , edge) {
		int x, y;
		sii(x, y);
		G[x].pb(y);
	}

	PrintEuler();

	reverse(all(ans));

	FOR(i , (int) ans.size()) printf("%d ", ans[i]);

}
