/*
Submitted by Amanullah Khan
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int height(int N){
      int i =0 ;
      
      
      for( i=0 ; i< 1000 ; i++)
      {
        int val = (i*(i+1))/2 ;
        if(val > N) 
          break ;
      }
      
      return i-1 ;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  