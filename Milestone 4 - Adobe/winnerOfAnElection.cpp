// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        string name="";
        int max_votes=0;
        
        unordered_map<string,int> ump;
        for(int i=0;i<n;i+=1)
        {
            ump[arr[i]]+=1;
            if(ump[arr[i]]>max_votes){
                max_votes=ump[arr[i]];
                 name=arr[i];
            }
            else if(ump[arr[i]]==max_votes)
            {
                if(name.empty())
                    name=arr[i];
                else
                {   
                    if(!lexicographical_compare(name.begin(),name.end(),arr[i].begin(),arr[i].end()))
                        name=arr[i];
                }
            }
        }
        
        return {name,to_string(max_votes)};
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends