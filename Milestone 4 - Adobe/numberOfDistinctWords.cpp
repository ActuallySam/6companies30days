// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    long long dp[1001][1001], M = 1000000007;
    
    long long solve(int n, int cnt, int k){
        if(n == 0) return 1;
        
        if(dp[n][cnt] != -1) return dp[n][cnt]%M; 
        
        if(cnt == k) return dp[n][cnt] = ((21%M)*(solve(n-1, 0, k))%M)%M;

        return dp[n][cnt] = (((21%M)*(solve(n-1, 0, k))%M)%M + (5*(solve(n-1, cnt+1, k))%M)%M)%M;
    }
  
    int kvowelwords(int N, int K) {
        memset(dp,-1,sizeof(dp));
        return solve(N, 0, K)%M;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends