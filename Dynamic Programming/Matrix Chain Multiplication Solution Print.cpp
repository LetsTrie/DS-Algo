#include<bits/stdc++.h>
using namespace std;
    
int dp[12][12];
int Row[12], Col[12];

int MCM(int st , int en) {
    if(st >= en) return 0;
    int &ret = dp[st][en];
    if(ret != -1) return ret;

    int ans = 1 << 30;
    for(int i = st ; i < en ; ++i)
        ans = min(ans, MCM(st, i) + MCM(i + 1, en) + Row[st] * Col[i] * Col[en]);

    return ret = ans;
}

void sol(int st, int en) {
    if(st == en) {
        printf("A%d",st + 1);
        return ;
    }
    printf("(");

    for(int i = st ; i < en ; ++i) {
        int l = MCM(st, i);
        int r = MCM(i + 1, en);
        if(dp[st][en] == l + r + Row[st] * Col[i] * Col[en]) {
            sol(st, i);
            printf(" x ");
            sol(i + 1, en);
            break;
        }
    }
    
    printf(")");
} 

int main() {
    int ks = 1, N;
    while(scanf("%d", &N) && N != 0) {
        for(int i = 0 ; i < N ; i++) scanf("%d %d", &Row[i], &Col[i]);
        for(int i = 0 ; i <= N ; i++) 
            for(int j = 0; j <= N ; j++) dp[i][j] = -1;
        MCM(0, N - 1);
        printf("Case %d: ", ks++);
        sol(0, N - 1);
        puts("");
    }

}
