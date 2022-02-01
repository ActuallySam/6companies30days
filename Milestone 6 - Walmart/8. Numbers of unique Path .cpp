/*
Submitted by Amanullah Khan
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int NumberOfPath(int a, int b)
    {
      int dp[a][b] ;
      for(int i=0 ; i< a ; i++) dp[i][0] = 1 ;
      for(int i=0 ; i< b ; i++) dp[0][i] = 1 ;
      for(int i=1 ; i< a ; i++) {
          for(int j=1 ; j< b ; j++) {
              dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
          }
      }
      
      int ans = dp[a-1][b-1] ;
      return ans ;
    }
};


int main()
{
   
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        cout << ob.NumberOfPath(a,b) << endl;
    }
}