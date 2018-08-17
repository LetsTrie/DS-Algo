#include<bits/stdc++.h>
 
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
 
#define fi first
#define endl '\n'
#define se second
#define MAXN 200004
#define inf INT_MAX // Be CareFul About The OverFlow
#define LL long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define mod 1000000007
#define EPS (double)1e-8
#define pii pair<int , int>
#define sz(x) (int) x.size()
#define sl(x) scanf("%lld",&x)
#define sii(x, y) si(x) , si(y)
#define all(x) (x).begin() , (x).end()
#define lg2(X) (31 - __builtin_clz(X))
#define Min(a , b) ( (a < b) ? a : b )
#define Max(a , b) ( (a < b) ? b : a )
#define llg2(X) (63 - __builtin_clzll(X))
#define rall(x) (x).rbegin() , (x).rend()
#define siii(x, y, z) si(x) , si(y) , si(z)
#define mem(a , b) memset((a), (b), sizeof(a))
#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOR1(i , n) for(int i = 1 ; i <= n ; i++)
#define _ceil(n, a) ((n)%(a)==0?((n)/(a)):((n)/(a)+1))
#define itr(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
template <typename T> T si(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}
 
using namespace std;
 
int fx[] = {1 , 0 , -1 , 0 , 1 , 1 , -1 , -1};
int fy[] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};

const int Max = 1000001;
bool F[Max + 10];
int cum[Max + 10];
int a , b , c;

void siv() {
	
	F[1] = 1 , F[0] = F[2] = F[3] = 0;
	for(int i = 4 ; i <= Max ; i += 2) F[i] = 1;
	for(int i = 3 ; i * i <= Max ; i += 2) {
		if(!F[i]) {
			for(int j = i * i , k = i << 1 ; j <= Max ; j += k) F[j] = 1;
		}
	}
	FOR1(i , Max) {
		cum[i] = cum[i - 1] + (F[i] == 0);
	}
}

bool task(int x) {
	for(int i = a ; i + x - 1 <= b ; i++) {
		if(cum[i + x - 1] - cum[i - 1] < c) {
			return false;
		}
	}
	return true;
}

int main()
{
   
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin); fout;
// #endif

	 siv();
	 siii(a , b , c);
	 int lo = 0 , hi = b - a + 1 , mid;
	 int ans = -1;
	 for(int itr = 1 ; itr <= 50 && lo <= hi ; itr++) {
	 	mid = ( hi + lo ) / 2;
	 	if(task(mid) == true) {
	 		hi = mid - 1;
	 		ans = mid;
	 	} else {
	 		lo = mid + 1;
	 	}
	 }
	 cout << ans << endl;
}
 
