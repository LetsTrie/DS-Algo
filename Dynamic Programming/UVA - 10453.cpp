#include<bits/stdc++.h> 
#define LL long long
using namespace std;

int main() {
   string str1;
   while(getline(cin, str1)) {
      string str2 = str1;
      int len = str1.size();
      reverse(str2.begin(), str2.end());
      int DP[len + 1][len + 1];
      for (int i = 0; i <= len; i++)
         for (int j = 0; j <= len; j++) {
            if (i == 0 || j == 0) DP[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) DP[i][j] = 1 + DP[i - 1][j - 1];
            else DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
         }
      printf("%d ", len - DP[len][len]);

      // PADRAQ
      // QARDAP

      string pprint = "";
      int i = len, j = len;
      while (i != 0 || j != 0) {
         if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) pprint += str1[i - 1], i--, j--;
         else if (i > 0 && DP[i][j] == DP[i - 1][j]) i--;
         else if (j > 0 && DP[i][j] == DP[i][j - 1]) j--;
      }

      //cout << pprint << endl;

      bool idx[len + 1];
      memset(idx, 0, sizeof idx);

      int lenp = -1 + (int) pprint.size();
      for (int i = 0; i < len && lenp >= 0; i++) {
         if (pprint[lenp] == str1[i]) {
            lenp--;
            idx[i] = 1;
         }
      }

      // for(int i = 0 ; i < len ; i++) {
      // 	if(idx[i]) cout << str1[i];
      // }
      // cout << endl;

      string st = "";
      int lo = 0, hi = len - 1;

      // PADRAQ

      while (lo < hi) {
         if (str1[lo] == str1[hi]) st += str1[lo++], hi--;
         else {
            if (!idx[lo] && idx[hi]) st += str1[lo++];
            else if (idx[lo] && !idx[hi]) st += str1[hi--];
            else st += str1[hi--];
         }
      }

      for (int i = 0; i < st.size(); i++) printf("%c", st[i]);
      if (lo == hi) printf("%c", str1[lo]);
      for (int i = st.size() - 1; i >= 0; i--) printf("%c", st[i]);
      puts("");
   }
}
