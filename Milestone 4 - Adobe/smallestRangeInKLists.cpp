// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
# define p pair<int,pair<int,int>>
class Solution{
    public:

    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          int range = INT_MAX;
          int mn=INT_MAX;
          int mx=INT_MIN;
          priority_queue<p,vector<p>,greater<p>> pq;
          
          
          int maxval=INT_MIN;
          for(int i=0;i<k;i+=1)
          { 
            maxval=max(maxval,arr[i][0]); 
            pq.push({arr[i][0],{i,0}});
          }
          
          while(true)
          {
            p top=pq.top();
            pq.pop();
              
            if(range>(maxval-top.first)){
                range = maxval-top.first;
                mn=top.first,mx=maxval;
            }
                
            if(top.second.second==n-1)
                break;
            
            else
            {
                maxval=max(maxval,arr[top.second.first][top.second.second+1]);
                pq.push({arr[top.second.first][top.second.second+1],{top.second.first,top.second.second+1}});
            }
       
          }
          
          return {mn,mx};
          
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends