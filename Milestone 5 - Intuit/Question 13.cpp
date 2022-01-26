#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
*/
int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size() ;
        vector<int> zeroes(n,0) ;
        
        for(int i = 0;i<n;i++){
            
            int cnt = 0;
            for(int j = n-1;j>=0;j--){
                
                if(grid[i][j] == 0){
                    cnt++;
                }
                else{
                    break;
                }
            }
            
            zeroes[i] = cnt ;
            //cout<<zeroes[i]<<endl;
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            int curr = i ;
            int req = n-i-1 ;
            
            //find that index greedily
            while(curr<n && zeroes[curr]<req) 
            {curr++ ;}
            
            if(curr == n){
                return -1;
            }
            
            ans +=curr-i ;
            
            while(curr>i){
                swap(zeroes[curr],zeroes[curr-1]) ;
                curr--;
            }
            
        }
        return ans;

        /*
        Time : O(N^2)
        Space :O(N)
        */
        
    }
int main() {
/**/
return 0;
}