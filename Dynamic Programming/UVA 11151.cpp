#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
   int N;
   scanf("%d", &N);
   getchar();
   while(N--) {
    string str1;
    getline(cin , str1);
    string str2 = str1;
    int len = str1.size();
    reverse(str2.begin() , str2.end());
    int DP[len + 1][len + 1];
    for(int i = 0 ; i <= len ; i++) for(int j = 0 ; j <= len ; j++) {
    	if(i == 0 || j == 0) DP[i][j] = 0;
    	else if(str1[i - 1] == str2[j - 1]) DP[i][j] = 1 + DP[i - 1][j - 1];
    	else DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
    }
    printf("%d\n", DP[len][len]);
   }
}
