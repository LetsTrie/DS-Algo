#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 20202;

vector< pair<int , int> > biclr;
vector<int> G[MAXN];
int vis[MAXN];
bool clr[MAXN];
int a , b , c;
int cnt;

bool dfs(int u , int cnt) {
  vis[u] = 1;
  for(int v : G[u]) {
    if(!vis[v]) {
      vis[v] = cnt;
      clr[v] = clr[u] ^ 1;
      if(clr[v]) biclr[cnt].second++;
      else biclr[cnt].first++;
      dfs(v , cnt);
    } else {
      if(clr[v] == clr[u]) return false;
    }
  }
  return true;
}

int dp[1200][1200];

int mn(int a , int b) {
  return (a < b) ? a : b;
}

int SubSum(int i = 1 , int make = mn(a , b)) {
  if(i > cnt) {
    if(make == 0) return 1;
    return 0;
  }
  if(dp[i][make] != -1) return dp[i][make];
  int a = 0 , b = 0;
  if(make - biclr[i].first >= 0)
    a = SubSum(i + 1 , make - biclr[i].first);
  if(make - biclr[i].second >= 0)
    b = SubSum(i + 1 , make - biclr[i].second);
  return dp[i][make] = a | b;
}

int main() {
   int test;
   cin >> test;
   while(test--) {
    cin >> a >> b >> c;
    for(int i = 0 ; i < c ; i++) clr[i] = 0;
    for(int i = 0 ; i < c; i++) {
      int x , y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    cnt = 1;
    bool flag = true;
    biclr.resize(a + b + 2);
    for(int i = 1 ; i <= (a + b) ; i++) {
      if(!vis[i]) {
        biclr[cnt].first++;
        bool flag = dfs(i , cnt++);
        if(!flag) break;
      }
    }
    biclr.resize(cnt);
    if(!flag) {
      cout << "no\n";
    } else {
      for(int i = 0 ; i <= cnt + 10 ; i++)
        for(int j = 0 ; j <= mn(a , b) + 10 ; j++)
          dp[i][j] = -1;
      if( SubSum() ) {
        cout << "yes\n";
      } else {
        cout << "no\n";
      }
    }
    biclr.clear();
    for(int i = 0 ; i <= (a + b) ; i++) G[i].clear();
    for(int i = 0 ; i <= (a + b) ; i++) vis[i] = 0 , clr[i] = 0;
  }
}
