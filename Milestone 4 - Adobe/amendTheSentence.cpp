// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {

        vector<int> index;
        s[0]=tolower(s[0]);
        index.push_back(0);
        for(int j=1;j<s.length();j+=1)
        {
            if(s[j]>='A' and s[j]<='Z')
            {   
                s[j]=tolower(s[j]);
                index.push_back(j);
            }
            
        }
        
        string temp="";
        for(int i=1;i<index.size();i+=1)
        {   
            temp+=s.substr(index[i-1],index[i]-index[i-1]);
            temp+=" ";
        }
        
        temp+=s.substr(index.back(),s.length()-index.back());
        return temp;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends