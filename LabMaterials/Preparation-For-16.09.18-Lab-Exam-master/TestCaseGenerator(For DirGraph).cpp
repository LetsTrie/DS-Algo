#include<bits/stdc++.h>
using namespace std;

#define MAX_VERTICES 100001
#define MAX_EDGES 100110

// From GeeksForGeeks 

int main()
{
	freopen("input.txt","w",stdout);

    set<pair<int, int>> container;
    set<pair<int, int>>::iterator it;
 
 
    srand(time(NULL));

    int NUM = 1 + rand() % MAX_VERTICES;

    int NUMEDGE = 1 + rand() % MAX_EDGES; 

    while (NUMEDGE > NUM*(NUM-1)/2)
        NUMEDGE = 1 + rand() % MAX_EDGES;

    printf("%d %d\n", NUM, NUMEDGE);

    for (int j=1; j<=NUMEDGE; j++)
    {
        int a = 1 + rand() % NUM;
        int b = 1 + rand() % NUM;
        pair<int, int> p = make_pair(a, b);

        while (container.find(p) != container.end())
        {
            a = 1 + rand() % NUM;
            b = 1 + rand() % NUM;
            p = make_pair(a, b);
        }
        container.insert(p);
    }

    for (it=container.begin(); it!=container.end(); ++it)
    {
        printf("%d %d\n", it->first, it->second);
    }
    container.clear();
    printf("\n");
 
    return(0);
}
