#include<bits/stdc++.h>
using namespace std;
const int MX = 10007;

vector<int>G[MX];
map<int, map<int, int> > bb;
bool vis[MX];
int low[MX], dis[MX];
int P[MX];

int t;
vector<pair<int,int> >bridges;

int cnt[MX];

void ART(int u)
{
    vis[u] = true;
    low[u] = dis[u] = ++t;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!vis[v]){
            P[v] = u;
            ART(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dis[u]){
                bridges.push_back({u,v});
                bb[u][v] = bb[v][u] = 1;
            }
        }
        else if( v != P[u])
            low[u] = min(low[u], dis[v]);
    }

}

int Root(int u)
{
    if(u == P[u]) return u;
    return P[u] = Root(P[u]);
}

int main()
{
    int ts , cs = 0;
    scanf("%d",&ts);
    while(ts--)
    {
        int n , m;
        scanf("%d %d",&n,&m);
        while(m--){
            int a, b;
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(P, -1, sizeof P);
        t = 0;
        bridges.clear();
        for(int i =0; i < n; i++)
            if(!vis[i])
                ART(i);
        for(int i =0; i <= n; i++) P[i] = i;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < G[i].size(); j++)
            {
                int v = G[i][j];
                if(bb[i][v] != 1)
                {
                    int u = Root(i);
                    v = Root(v);
                    if( u != v)
                        P[u] = v;
                }

            }
        }
        for(int i = 0; i < bridges.size(); i++){
            int u = bridges[i].first;
            int v = bridges[i].second;
            u = Root(u);
            v = Root(v);
            cnt[u]++;
            cnt[v]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
          if(cnt[i]==1) ans++;
        ans = (ans + 1)/2;
        printf("Case %d: %d\n", ++cs, ans);
        bb.clear();
        for(int i = 0; i < n+5; i++) G[i].clear() , cnt[i] = 0, vis[i] = 0;
    }
}
