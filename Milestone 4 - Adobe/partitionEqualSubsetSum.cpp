// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum =0;
        for(int i =0;i<N;i+=1)
            sum+=arr[i];
            
        if(sum%2)
            return 0;
            
        return helper(arr,N,sum/2);
    }
    
    int helper(int arr[],int N,int s)
    {
        vector<vector<int>> dp(N+1,vector<int>(s+1,0));
        dp[0][0]=1;
            
        for(int i=1;i<=N;i+=1)
        {
            for(int j=1;j<=s;j+=1)
            {
                if(j>=arr[i-1])
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]=dp[i-1][j];

            }
        
        }
    
        return dp[N][s];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends