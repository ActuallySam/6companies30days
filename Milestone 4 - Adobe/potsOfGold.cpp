// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    int maxCoins(vector<int>&arr,int n)
    {
	    //Write your code here
	   vector<vector<int>> dp(501,vector<int>(501,-1));
	   return recur(arr,n,0,n-1,dp);;
    }
    
    int recur(vector<int> &arr,int n, int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return 0;
        }
        
        if(i==j)
            return dp[i][j]=arr[i];
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int l = arr[i] + min(recur(arr,n,i+2,j,dp),recur(arr,n,i+1,j-1,dp));
        int r = arr[j] + min(recur(arr,n,i+1,j-1,dp),recur(arr,n,i,j-2,dp));
        
        return dp[i][j]=max(l,r);
        
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends