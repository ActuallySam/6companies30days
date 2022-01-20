// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0;
        int n=str.length();
        int ans =0;
        while(i<n and str[i]==' ')
            i+=1;
            
        
        int sign =1;
        if(str[i]=='-'){
            sign=-1;
            i+=1;
        }
        
        for(;i<n;i+=1)
        {   
            if(str[i]>='0' and str[i]<='9')
                ans  = ans*10 + (str[i]-'0')*sign;
            else
                return -1;
        }
            
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends