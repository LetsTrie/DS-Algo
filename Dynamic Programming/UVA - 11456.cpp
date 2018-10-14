#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--) {
        int N;
        scanf("%d",&N);
        int arr[N], lis[N], lds[N];
        int mx = 0;
        for(int i = 0 ; i < N ; i++) scanf("%d",&arr[i]);;
        for(int i = N - 1 ; i >= 0 ; i--) {
            lis[i] = lds[i] = 1;
            for(int j = i + 1 ; j < N ; j++) {
                if(arr[i] < arr[j]) lis[i] = max(lis[i] , lis[j] + 1);
                if(arr[i] > arr[j]) lds[i] = max(lds[i] , lds[j] + 1);
            }
            mx = max(mx , lis[i] + lds[i] - 1);
        }
        printf("%d\n", mx);
    }
}
