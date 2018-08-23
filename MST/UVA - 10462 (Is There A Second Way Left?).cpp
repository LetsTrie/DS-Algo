#include<bits/stdc++.h>

#define fi first
#define endl '\n'
#define se second
#define inf 1000000000000 // (10 ^ 12) Be CareFul About The OverFlow
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

// int fx[] = {1 , 0 , -1 , 0 , 1 , 1 , -1 , -1};
// int fy[] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};

/********************* OverFlow ***********************/

const int MAXN = 100 + 10;

int par[MAXN];
vector<pair<int , pii> > G;

int rep(int u) {
	if(u == par[u]) return u;
	return par[u] = rep(par[u]);
}

int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
#endif
    int test;
    si(test);
    while(test--) {
        int ver ,eg;
        sii(ver , eg);
        FOR1(i , ver) par[i] = i;
        while(eg--) {
            int x , y ,z ;
            siii(x , y , z); 
            G.pb({z , {Min(y , x) , Max(y , x)}});
        }
        sort(all(G));
        vector<pii> BestMST;
        FOR(i , sz(G)) {
          int u = G[i].se.fi , v = G[i].se.se , w = G[i].fi;
          int ru = rep(u) , rv = rep(v);
          if(ru != rv) {
          	par[ru] = rv;
          	BestMST.pb({Min(u , v) , Max(u , v)});
          }
        }
        int cnt = 0;
        FOR1(i , ver) if(i == rep(i)) cnt++;
        bool GotTheFirstOne = 0;
        if(cnt == 1) GotTheFirstOne = 1;
	  LL mn = inf;
        if(GotTheFirstOne) {
	       for(auto it : BestMST) {
	       	int uu = it.fi , vv = it.se;
	       	FOR1(i , ver) par[i] = i;
	       	LL sum = 0; bool T_T = 0;
	       	FOR(i , sz(G)) {
	          		int u = G[i].se.fi , v = G[i].se.se , w = G[i].fi;
	          		u = Min(u , v) , v = Max(u , v);
	          		if(u == uu && v == vv && T_T == 0) {
	          			T_T = 1;
	          			continue;	
	          		} 
	          		int ru = rep(u) , rv = rep(v);
	          		if(ru != rv) {
	         			par[ru] = rv;
	         			sum += w;	
	         		}
	        	}
	        	int cnt = 0;
	        	FOR1(i , ver) if(i == rep(i)) cnt++;
	        	if(cnt == 1) mn = Min(mn , sum);
	         }
	   }

	   static int ks = 1;
	   printf("Case #%d : ", ks++);

	   if(!GotTheFirstOne) {
	   	printf("No way\n");
	   } else if(GotTheFirstOne && mn == inf) {
	   	printf("No second way\n");
	   } else if(GotTheFirstOne && mn != inf) {
	   	printf("%lld\n", mn);
	   } G.clear();
    }
}
