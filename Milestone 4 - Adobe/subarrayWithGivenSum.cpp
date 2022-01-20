// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int i =0;
        int j =0;
        
        long long sum = 0;
        
        while(i<n and j<n)
        {
            sum+=arr[j];
        
            if(sum==s)
                return {i+1,j+1};
            
            else if(sum>s)
            {   
                
                while(sum>s)
                {
                    sum-=arr[i];
                    i+=1;
                }
  
                if(sum==s)
                    return {i+1,j+1};
                
            }
            
            j+=1;
   
            
        }
    
        return {-1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends