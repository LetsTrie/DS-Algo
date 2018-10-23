#include<bits/stdc++.h>
using namespace std;
#define MX 107
vector<int>G[MX];
int in[MX];
map<pair<int,int>,int> edge;
int nc;
vector<pair<int,int> > ans;

void Euler(int u)
{
    for(int i =0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(edge[{u,v}])
        {
            edge[{u,v}]--;
            edge[{v,u}]--;
            Euler(v);
            nc++;
            ans.push_back({v,u});
        }
    }
}


int main()
{
    int t, cs = 0;
    cin >> t;
    while(t--)
    {
        int a, b;
        int n,m, N = -1;
        cin >> n;
        nc = 0;
        m = n;
        while(m--)
        {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
            edge[ {a,b}]++;
            edge[ {b,a}]++;
            in[a]++;
            in[b]++;
            N = max(N,max(a,b));
        }
        int cnt = 0;
        for(int i =1; i <= N; i++)
            if(in[i]&1)
                cnt++;
        printf("Case #%d\n",++cs);
        if(cnt)
            puts("some beads may be lost");
        else
        {
            Euler(a);
            if(nc != n)
                puts("some beads may be lost");
            else
                for(int i =0; i < ans.size(); i++)
                    cout << ans[i].first << " " << ans[i].second << endl;
        }
        if(t)
            puts("");
        for(int i =0; i < N+5; i++)
            G[i].clear(), in[i] = 0;
        edge.clear();
        ans.clear();
    }
}
