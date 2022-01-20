// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        int ans1= helper(A,n);
        reverse(A,A+n);
        int ans2= helper(A,n);
        return max(ans1,ans2);
    }
    
    int helper(int A[],int n){
        vector<vector<int>>dp(n,vector<int>(11000,0));
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++)
            {
                if(A[i] >= A[j])
                {
                    dp[i][A[i]-A[j]] = max(2,1 + dp[j][A[i]-A[j]]);
                    ans = max(ans,dp[i][A[i]-A[j]]);
                }
            }
        }
    
        return ans;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends