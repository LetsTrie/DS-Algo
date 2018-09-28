#include<bits/stdc++.h>
using namespace std;

#define N 100010
#define pii pair<int, int>
#define fi first
#define se second

vector<pii> Bcc[N];
vector<int> G[N];
stack<pii> st;
bool vis[N];
int dis[N];
int low[N];
int timer;
int idx; 

void BiconnectedComponents(int u , int par = -1) {
	vis[u] = 1;
	dis[u] = low[u] = ++timer;
	int child = 0;
	for(int i = 0; i < (int) G[u].size(); ++i) {
		int v = G[u][i];
		if(v == par) continue;
		if(!vis[v]) {
			++child;
			st.push(make_pair(u , v));
			BiconnectedComponents(v , u);
			low[u] = min(low[u], low[v]);
			if((par != -1 && dis[u] <= low[v]) || (par == -1 && child > 1)) {
				while(st.top().fi != u && st.top().se != v) {
					Bcc[idx].push_back(make_pair(st.top().fi , st.top().se));
					st.pop();
				}
				Bcc[idx++].push_back(make_pair(st.top().fi , st.top().se));
				st.pop();
			}
		} else if(dis[u] > dis[v]) {
			low[u] = min(low[u], dis[v]);
			st.push(make_pair(u , v));
		}
	}
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	
	for(int i = 0; i < e; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for(int i = 0; i < v; ++i) {
		if(vis[i] == 0) {
			BiconnectedComponents(i);
			bool checker = 0;
			while(!st.empty()) {
				Bcc[idx].push_back(pii(st.top().fi , st.top().se));
				st.pop();
				checker = 1;
			}
			if(checker) idx++;
		}
	}

	for(int i = 0; i < idx; ++i) {
		printf("%dth Component is\n", i + 1);
		for(int j = 0; j < (int) Bcc[i].size(); ++j) {
			printf("%d %d\n", Bcc[i][j].fi, Bcc[i][j].se);
		}
	}
}
