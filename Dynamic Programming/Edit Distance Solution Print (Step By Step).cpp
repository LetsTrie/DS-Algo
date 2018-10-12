#include<stdio.h>
#include<string.h>

int min(int x , int y) {
    return (x < y) ? x : y;
}

int main(){
    char str1[22] , str2[22];
    while(scanf("%s",str1) && str1[0] != '#') {
        scanf("%s",str2);
        int len1 = (int) strlen(str1), i;
        int len2 = (int) strlen(str2), j;
        int dp[len1 + 1][1 + len2];
        for(i = 0 ; i <= len1 ; ++i) {
            for(j = 0 ; j <= len2 ; ++j) {
                if(j == 0 || i == 0) dp[i][j] = i + j;
                else if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j] , min(dp[i][j - 1] , dp[i - 1][j - 1]));
            }
        }

        i = len1 , j = len2;
        while(i > 0 || j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                i-- ;
                j-- ;
            }
            else if(i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
                printf("C%c%02d",str2[j - 1], i);
                i--;
                j--;
            }
            else if(i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
                printf("D%c%02d",str1[i - 1], i);
                i--;
            }
            else if(j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
                printf("I%c%02d",str2[j - 1], i + 1);
                j--;
            }
        }
        printf("E\n");
    }
}
