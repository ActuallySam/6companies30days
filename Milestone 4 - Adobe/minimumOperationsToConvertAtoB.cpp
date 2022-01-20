// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        // return recur(A,B,N,M);
        vector<int> nums; // elements of A present in B
        for(int i=0;i<N;i+=1)
            if(binarySearch(B,M,A[i]))
                nums.push_back(A[i]);
        
        return (N+M-2*lisSize(nums));
        
    }
    
    bool binarySearch(int B[],int M,int num)
    {
        int l = 0;
        int h = M-1;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(B[mid]==num)
                return true;
            else if(B[mid]>num)
                h = mid-1;
            else
                l = mid+1;
            
        }
        
        return false;
        
        
    }
    
    int lisSize(vector<int> nums){
        vector<int> lis;
        if(nums.empty())
            return 0;
        lis.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i+=1)
        {
            if(nums[i]>lis.back())
                lis.push_back(nums[i]);
            else
            {
                int idx=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[idx]=nums[i];
                
            }
            
        }
        
        return lis.size();
    }
    
    // TLE 
    // int recur(int A[],int B[],int N,int M)
    // {
    //     if(N==0)
    //         return M;
    //     if(M==0)
    //         return N;
            
    //     if(A[N-1]==B[M-1]){
    //         return recur(A,B,N-1,M-1);
    //     }
        
    //     int insert=1+recur(A,B,N,M-1);
    //     int del = 1+recur(A,B,N-1,M);
        
    //     return min(insert,del);
    // }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends