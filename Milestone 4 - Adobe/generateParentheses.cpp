// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        string curr="";
        recur(0,0,n,curr);
        return ans;
    }
    
    void recur(int open,int close,int n,string &curr)
    {
        if(close==n)
        {
            ans.push_back(curr);
            return;
        }
        
        if(open<n)
        {   
            curr+="(";
            recur(open+1,close,n,curr);
            curr.pop_back();
        }
        
        if(close<open)
        {
            curr+=")";
            recur(open,close+1,n,curr);
            curr.pop_back();
        }
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends