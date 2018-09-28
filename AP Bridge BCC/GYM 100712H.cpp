#include<bits/stdc++.h>
using namespace std;

template <typename T> T si(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}

#define N 100010
#define pii pair<int, int>
#define fi first
#define se second

map<pii, bool> bridge;
vector<int> newG[N];
vector<pii> temp;
vector<int> G[N];
bool vis[N];
int dis[N];
int low[N];
int timer;
int vv,e;

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

int lvl[N];
int id;
int mxlvl;
int mxnode;

void bfs(int k) {
	for(int i = 0 ; i < vv ; i++) vis[i] = 0 , lvl[i] = 0;
	queue<int> Q;
	Q.push(k);
	vis[k] = 1;
	mxlvl = mxnode = 0;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i = 0 ; i < (int) newG[u].size() ; ++i) {
			int v = newG[u][i];
			if(vis[v] == 0) {
				Q.push(v);
				vis[v] = 1;
				lvl[v] = lvl[u] + 1;
				if(mxlvl < lvl[v]) {
					mxlvl = lvl[v];
					mxnode = v;
				}
			}
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

void RIP() {
	for(int i = 0 ; i < vv ; i++) {
		G[i].clear();
		newG[i].clear();
		lvl[i] = vis[i] = dis[i] = low[i] = 0;
		clr[i] = i;
	}
	temp.clear();
	bridge.clear();
}

int main()
{
	int test;
	si(test);
	while(test--) {
		si(vv), si(e);
		for(int i = 0; i < e; ++i) {
			int x, y;
			si(x) , si(y);
			x-- , y--;
			G[x].push_back(y);
			G[y].push_back(x);
			temp.push_back(pii(x , y));
		}

		for(int i = 0; i < vv; ++i) {
			clr[i] = i;
			if(vis[i] == 0) Bridge(i); 
		}

		for(int i = 0; i < e; ++i) {
			int u = temp[i].fi;
			int v = temp[i].se;
			int x = min(u , v);
			int y = max(u , v);
			if(bridge[pii(x , y)] == true) continue;
			unite(x , y);
		}

		int edge = 0;
		for(int i = 0 ; i < e; i++) {
			int u = temp[i].fi;
			int v = temp[i].se;	

			int x = rep(min(u , v));
			int y = rep(max(u , v));

			if(x == y) continue;
			edge++;
			newG[x].push_back(y);
			newG[y].push_back(x);
		}
		bfs(0);
		bfs(mxnode);
		printf("%d\n", edge - mxlvl);
		RIP();
	}
}
