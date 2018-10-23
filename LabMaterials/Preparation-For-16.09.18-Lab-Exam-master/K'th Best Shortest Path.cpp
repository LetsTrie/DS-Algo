#include<bits/stdc++.h>
 
#define LL long long
#define mem(x , v) memset(x , v , sizeof x)
#define fr(i , N) for(int i = 0 ; i < N ; i++)
#define frr(i , N) for(int i = N - 1 ; i >= 0 ; i--)
#define fr1(i , N) for(int i = 1 ; i <= N ; i++)
#define vi vector<int>
#define sz(v) ( (int) v.size() )
#define pii pair<int , int>
#define mp make_pair
#define tii tuple<int , int , int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inside(x , y) (x >= 0 && x < r && y >= 0 && y < c)
#define MAXN 101000
#define MAXRC 2002
#define INF INT_MAX
#define endl '\n'
 
using namespace std;
 
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction
 
vector<int> dist[MAXN];
int K; // K'th Path
int v , e;
vector<pii> G[MAXN];
priority_queue< pair<int , int> > pq;
 
void KthBestPathUsingDijkstra() {
    while(!pq.empty()) pq.pop();
    fr1(i , v) dist[i].clear();
    pq.push(mp(0 , 1));
    while(!pq.empty()) {
        int u = pq.top().se;
        int cost = -pq.top().fi;
        pq.pop();
        if(dist[u].empty()) dist[u].pb(cost);
        else if(dist[u].back() != cost) dist[u].pb(cost);
        if(sz(dist[u]) > K) continue;
        fr(i , sz(G[u])) {
            int v = G[u][i].fi;
            int w = G[u][i].se;
            if(sz(dist[v]) == K) continue;
            pq.push(mp(-(cost + w) , v));
        }
    }
    cout << dist[v][K - 1] << '\n';
}
 
int main()
{
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int test;
    cin >> test;
    int T = 1;
    while(test--) {
        cin >> v >> e;
        fr(i , e) {
            int x , y , z;
            cin >> x >> y >> z;
            G[x].pb(mp(y , z));
            G[y].pb(mp(x , z));
        }
        K = 2; // it means the SecondBestPath
        cout << "Case " << (T++) << ": ";
        KthBestPathUsingDijkstra();
        fr1(i , v) G[i].clear();
    }
}
