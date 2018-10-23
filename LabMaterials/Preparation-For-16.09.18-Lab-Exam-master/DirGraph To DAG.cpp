#include<bits/stdc++.h>
#define MAXN 101010
using namespace std;

vector<int> G[MAXN]; // Main Graph
vector<int> revG[MAXN]; // Reverse Graph
vector<int> comp[MAXN]; // SCC component
vector<int> newGraph[MAXN]; // DAG 
stack <int> st;
bool vis[MAXN];
int num[MAXN]; // Component Number Of a Particular Node
int idx;

void SCC(int u , int Flag) {
	vis[u] = 1;
	int len = (!Flag) ? G[u].size() : revG[u].size();
	for(int i = 0 ; i < len ; i++) {
		int v = (!Flag) ? G[u][i] : revG[u][i];
		if(!vis[v]) SCC(v , Flag);
	}
	if(!Flag) st.push(u);
	else comp[idx].push_back(u) , num[u] = idx;
}

void DAG(int u) {
	vis[u] = 1;
	for(int i = 0 ; i < G[u].size() ; i++) {
		int v = G[u][i];
		if(num[u] != num[v]) newGraph[ num[u] ].push_back( num[v] );
		if(!vis[v]) {
			DAG(v);
		}
	}
}

int main() {	

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int vertex , edge;
	cin >> vertex >> edge;

	for(int i = 1 ; i <= edge ; i++) {
		int x , y;
		cin >> x >> y;
		G[x].push_back(y);
		revG[y].push_back(x);
	}

	for(int i = 1 ; i <= vertex ; i++) {
		vis[i] = 0;
		sort(G[i].begin() , G[i].end());
		sort(revG[i].begin() , revG[i].end());
	}

	for(int i = 1 ; i <= vertex ; i++) if(!vis[i]) SCC(i , 0);
	for(int i = 1 ; i <= vertex ; i++) vis[i] = 0; idx = 1;
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		if(!vis[u]) {
			SCC(u , 1);
			idx++;
		}
	}
	for(int i = 1 ; i <= vertex ; i++) vis[i] = 0;
	for(int i = 1 ; i <= vertex ; i++) {
		if(!vis[i]) DAG(i);
	}

	cout << "So The Compressed From (DAG) is:" << '\n';
	for(int i = 1; i <= vertex ; i++) {
		sort(newGraph[i].begin() , newGraph[i].end());
		for(int j = 0 ; j < newGraph[i].size() ; j++) {
			cout << i << " " << newGraph[i][j] << '\n';
		}
	}
}

/*

Test Case : 

20 24
1 2 
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 1
1 13
13 10
10 11
11 12
12 13
12 16
16 17
17 15
15 14
14 16
3 17
8 18
18 19
19 20
20 18

*/
