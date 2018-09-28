#include<bits/stdc++.h>
using namespace std;
 
#define N 100010
#define pii pair<int, int>
#define fi first
#define se second
 
map<pii, bool> bridge;
//vector<int> newG[N];
vector<pii> temp;
vector<int> G[N];
bool vis[N];
int dis[N];
int low[N];
int in[N];
int timer;
int v,e;
int idx;
 
void Bridge(int u , int par = -1) {
    vis[u] = 1;
    dis[u] = low[u] = ++timer;
    int child = 0;
    for(int i = 0; i < (int) G[u].size(); ++i) {
        int v = G[u][i];
        if(v == par) continue;
        if(!vis[v]) {
            ++child;
            Bridge(v , u);
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]) {
                int x = min(u , v);
                int y = max(u , v);
                bridge[pii(x , y)] = true;
            }
        } else if(dis[u] > dis[v]) {
            low[u] = min(low[u], dis[v]);
        }
    }
}
 
int clr[N];
 
int rep(int x) {
    if(x == clr[x]) return x;
    return clr[x] = rep(clr[x]);
}
 
void unite(int x, int y) {
    int rx = rep(x);
    int ry = rep(y);
    if(rx != ry) {
        if(rx < ry) swap(rx, ry);
        clr[rx] = ry;
    }
}
 
void AllClear()
{
    for(int i = 0 ; i < v ; i++) {
        G[i].clear();
        clr[i] = i;
        low[i] = dis[i] = vis[i] = in[i] = 0;
    }
    temp.clear();
    bridge.clear();
}
 
int main()
{
    int ks = 1;
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d", &v, &e);
        for(int i = 0; i < e; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
            temp.push_back(pii(x , y));
        }
 
        for(int i = 0; i < v; ++i) {
            if(vis[i] == 0) Bridge(i);
        }
 
        for(int i = 0; i < v; ++i) {
            clr[i] = i;
        }
 
        for(int i = 0; i < e; ++i) {
            int u = temp[i].fi;
            int v = temp[i].se;
            int x = min(u , v);
            int y = max(u , v);
            if(bridge[pii(x , y)] == true) continue;
            unite(x , y);
        }
 
        for(int i = 0 ; i < e; i++) {
            int u = temp[i].fi;
            int v = temp[i].se;
            int x = rep(min(u , v));
            int y = rep(max(u , v));
 
            if(x == y) continue;
            //newG[x].push_back(y);
            //newG[y].push_back(x);
            in[x]++;
            in[y]++;
        }
        int leaf = 0;
        for(int i = 0 ; i < v ; i++) {
            if(in[i] == 1) leaf++;
        }
        printf("Case %d: %d\n", ks++, (int) (leaf + 1) >> 1);
        AllClear();
    }
}
