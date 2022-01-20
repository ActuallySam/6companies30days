// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.length();
        
        if(n%2)
        {
            int i =n/2;
            i-=2;
        
            while(i>=0)
            {
                if(N[i]<N[i+1])
                    break;
                
                i-=1;
            }
        
            if(i<0)
                return "-1";
            
            int j = n/2 - 1;
            while(j>=0)
            {
                if(N[j]>N[i])
                    break;
            
                j-=1;
            }
            
            swap(N[i],N[j]);
            swap(N[n-i-1],N[n-j-1]);
        
        
            sort(N.begin()+i+1,N.begin()+n/2);
            sort(N.begin()+n/2+1,N.begin()+n-i-1,greater<int>());
        }
        
        else
        {
            int i =n/2;
            i-=1;
        
            while(i>=0)
            {
                if(N[i]<N[i+1])
                    break;
                
                i-=1;
            }
        
            if(i<0)
                return "-1";
            
            int j = n/2;
            while(j>=0)
            {
                if(N[j]>N[i])
                    break;
            
                j-=1;
            }
            
            swap(N[i],N[j]);
            swap(N[n-i-1],N[n-j-1]);
        
        
            sort(N.begin()+i+1,N.begin()+n/2);
            sort(N.begin()+n/2,N.begin()+n-i-1,greater<int>());
            
            
            
        }
        
        
       return N;
    }
};

// 35 4 53
// 012 3 456
// 83633638

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends