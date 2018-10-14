#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int mul, ev;
char x[2222], y[2222];
vector<int> digit;
int dp[2][2][2002][2][2002];

int rec(int st = 1, int sm = 0, int pos = 0, int OddOrEven = 0, int val = 0) {
    if(pos == (int) digit.size()) {
        return (!st && !val);
    }
    int &ret = dp[st][sm][pos][OddOrEven][val];
    if(dp[st][sm][pos][OddOrEven][val] != -1) return ret;
    dp[st][sm][pos][OddOrEven][val] = 1;
    int ans = 0;
    if(OddOrEven) {
        if(( sm == 1 || ev <= digit[pos]))ans = (ans + rec(0, sm || (ev < digit[pos]) , pos + 1, 0 , ((val * 10) + ev) % mul)) % mod;
    }
    else {
        int mx = (sm == 1) ? 9 : digit[pos];
        for(int i = (st == 1) ; i <= mx ; i++) {
            if(i == ev) continue;
            ans = (ans + rec(0, sm || (i  < digit[pos]) , pos + 1, 1, ((val * 10) + i) % mul)) % mod;
        }
    }
    if(st) ans = (ans + rec(1, 1, pos + 1, 0 , 0)) % mod;
    return ret = ans;
}

int solve()
{
    digit.clear();
    int len = strlen(y);
    for(int i = 0 ; i < len ; i++) digit.push_back(y[i] - '0');
    memset(dp, -1, sizeof dp);
    int ans;
    ans = rec() % mod;
    digit.clear();
    len = strlen(x);
    for(int i = 0 ; i < len ; i++) digit.push_back(x[i] - '0');
    memset(dp, -1, sizeof dp);
    ans = (ans % mod - rec() % mod) % mod;
    ans = (ans + mod) % mod;
    int temp = 1;
    int num = 0;
    for(int i = 0 ; i < len ; i++) {
        int ch = (x[i] - '0');
        num = ((num * 10) + ch) % mul;
        if((i & 1) && (x[i] - '0') != ev) temp = 0;
        if(!(i & 1) && (x[i] - '0') == ev) temp = 0;
    }
    if(num) temp = 0;
    return ans + temp;
}


int main() 
{
    scanf("%d %d",&mul,&ev);
    scanf("%s %s",x,y);
    printf("%d\n", solve());
}
