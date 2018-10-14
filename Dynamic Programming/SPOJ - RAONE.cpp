#include<bits/stdc++.h>
using namespace std;

int x , y;
vector<int> digit;
int dp[2][2][9][9][46][46];
bool vis[2][2][9][9][46][46];

int rec(int st = 1, int sm = 0, int pos = 0, int real = 0, int even = 0, int odd = 0) {
    if(pos == (int) digit.size()) return (even - odd == 1 && real % 2 == 0) || (odd - even == 1 && real % 2 == 1);  
    int &ret = dp[st][sm][pos][real][even][odd];
    if(vis[st][sm][pos][real][even][odd]) return ret;
    vis[st][sm][pos][real][even][odd] = 1;
    int ans = 0;
    int mx = (sm == 1) ? 9 : digit[pos];
    for(int i = (st == 1) ; i <= mx ; i++) {
        int pluse = (real & 1) ? 0 : i;
        int pluso = (real & 1) ? i : 0;
        ans += rec(0, sm || (i < digit[pos]) , pos + 1, real + 1,  even + pluse, odd + pluso);
    }
    if(st) ans += rec(1, 1, pos + 1, 0,  0 , 0);
    return ret = ans;
}

void makedigit(int x) {
    while(x) { 
        digit.push_back(x % 10);
        x /= 10;
    }
    reverse(digit.begin() , digit.end()); 
}

int solve()
{
    digit.clear();
    makedigit(y);
    memset(vis, 0, sizeof vis);
    int ans;
    ans = rec();
    digit.clear();
    makedigit(x - 1);
    memset(vis, 0, sizeof vis);
    ans -= rec();
    return ans;
}


int main() 
{
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d %d",&x,&y);
        if(x > y) swap(x , y);
        printf("%d\n", solve());
    }
}
