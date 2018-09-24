#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
	if(!a) {
		x = 0 , y = 1;
		return b;
	}
	int x1 , y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - /*Floor*/ (b / a) * x1;
	y = x1;
	return d;
}

int main() {	

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	
	int x , y;
	cout << gcd(6, 8, x, y) << endl;

}
