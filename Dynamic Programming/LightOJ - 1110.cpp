#include<bits/stdc++.h>
using namespace std;

int main() {
	int test, ks = 1;
	cin >> test;
	while(test--) {
		string str1 , str2;
		cin >> str1 >> str2;
		// cout << str1 << " " << str2 << endl;
		int len1 = (int) str1.size();
		int len2 = (int) str2.size();
		string str[len1 + 1][len2 + 1];
		int DP[len1 + 1][len2 + 1];
		for(int i = 0; i <= len1 ; i++) {
			for(int j = 0 ; j <= len2 ; j++) {
				if(i == 0 || j == 0) DP[i][j] = 0, str[i][j] = "";
				else if(str1[i - 1] == str2[j - 1]) {
					//cout << str[i][j] << " " << str1[i - 1] << endl;
					DP[i][j] = DP[i - 1][j - 1] + 1 , str[i][j] = str[i - 1][j - 1] + str1[i-1];
				}
				else {
					if(DP[i - 1][j] > DP[i][j - 1]) str[i][j] = str[i - 1][j];
					else if(DP[i - 1][j] < DP[i][j - 1]) str[i][j] = str[i][j - 1];
					else str[i][j] = (str[i - 1][j] < str[i][j - 1]) ? str[i - 1][j] : str[i][j - 1];
					DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
				}
			}
		}
		// for(int i = 0; i <= len1 ; i++) {
		// 	for(int j = 0 ; j <= len2 ; j++) {
		// 		cout << str[i][j] << endl;
		// 	}
		// }
		//cout << DP[len1][len2] << endl;
		printf("Case %d: ", ks++);
		if(str[len1][len2].empty()) cout << ":(" << "\n";
		else cout << str[len1][len2] << "\n";
	}
}
