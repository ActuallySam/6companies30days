/*
Submitted by Amanullah Khan
*/

#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

class Solution{
    public:
    
    long long power(int N,int R)
    {
       return solve(N ,R) % 1000000007 ;
        
    }
    
    long long solve(int N ,int R) {
        if(R==0) return 1 ;
        
        long long result = power(N,R/2) ;
        result = (result *result) % 1000000007 ;
        if(R&1)
           return N * result ;
        else
            return result ;
    }       

};


long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}