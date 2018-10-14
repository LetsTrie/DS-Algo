#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N) != EOF)  {
        vector<int> arr(N), temp;
        for(int i = 0 ; i < N ; i++) cin >> arr[i];
        int is[N] , ds[N];
        for(int i = 0 ; i < N ; i++) is[i] = ds[i] = 0;
        for(int i = 0 ; i < N ; i++) 
        {
            vector<int>::iterator iv = lower_bound(temp.begin() , temp.end(), arr[i]);
            if(temp.end() == iv) temp.push_back(arr[i]);
            else temp[iv - temp.begin()] = arr[i];
            is[i] = (int) temp.size();
        }
        temp.clear();
        reverse(arr.begin() , arr.end());
        for(int i = 0 ; i < N ; i++) 
        {
            vector<int>::iterator iv = lower_bound(temp.begin() , temp.end(), arr[i]);
            if(temp.end() == iv) temp.push_back(arr[i]);
            else temp[iv - temp.begin()] = arr[i];
            ds[i] = (int) temp.size();
        }

        int mx = 0;
        for(int i = 0 ; i < N ; i++){
            mx = max(mx , min(is[i] , ds[N - i - 1]));
        }
        printf("%d\n", ((mx - 1) * 2 ) + 1);
    }
}
