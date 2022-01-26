#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : 
*/
Node* solve(vector<vector<int>>& grid,int row_s,int row_e,int col_s,int col_e){
        
        int n = row_e-row_s ;
        
        if(n == 1){
            return new Node(grid[row_s][col_s],true);
        }
        
        
        int ones = 0,zeroes = 0;
        for(int i = row_s;i<row_e;i++){
            for(int j = col_s;j<col_e;j++){
                if(grid[i][j] == 0){
                    zeroes++;
                }
                else{
                    ones++ ;
                }
            }
        }
        Node* root = NULL ;
        if((ones == n*n && zeroes==0) || (zeroes == n*n && ones == 0) ){
            //where grid having either all zeroes or all ones
            bool isval = false ; //== 0
            if(ones == n*n){
                isval = true ;
            }
            root = new Node(isval,true);
        }
        else{
            //where grid having different values
            //so we have to divide it into 4 parts
            root = new Node(true,false) ;
            root->topLeft = solve(grid,row_s,row_s+n/2,col_s,col_s+n/2) ;
            root->topRight = solve(grid,row_s,row_s+n/2,col_s+n/2,col_e) ;
            root->bottomLeft = solve(grid,row_s+n/2,row_e,col_s,col_s+n/2);
            root->bottomRight = solve(grid,row_s+n/2,row_e,col_s+n/2,col_e) ;
            
        }
        
        return root ;
        
    }

Node* construct(vector<vector<int>>& grid) {
        int n = grid.size() ;
        return solve(grid,0,n,0,n);
        /*
        Time : O(4^N)
        Space : O(N) //recursive stack
        */
    }
int main() {
/**/
return 0;
}