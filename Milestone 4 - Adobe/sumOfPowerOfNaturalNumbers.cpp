// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long numOfWays(int n, int x)
    {
        // code here
        vector<int> sq;
        for(int i=1;i<=n;i+=1)
        {   
            int temp = pow(i,x);
            if(temp>n)
                break;
            sq.push_back(temp);
        }   
        int m=sq.size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        for(int i=0;i<=m;i+=1)
            dp[i][0]=1;
            
        for(int i=1;i<=m;i+=1)
        {
            for(int j=1;j<=n;j+=1)
            {
                if((j-sq[i-1])>=0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-sq[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
                
                
            }
        }
        
        return dp[m][n];
        
            
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends