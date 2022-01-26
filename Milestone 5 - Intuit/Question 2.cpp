#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://practice.geeksforgeeks.org/problems/word-search/1/
*/

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool dfs_helper(int ind,string word,vector<vector<char>> board,int i,int j,
    int r,int c,vector<vector<bool>>& visited){
        if(ind == word.length()){
            return true ;
        }
        for(int k = 0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k] ;
if(nx>=0 && ny>=0 && nx<r && ny<c && !visited[nx][ny] && board[nx][ny] == word[ind]){ 
                visited[i][j] = true ;
        if(dfs_helper(ind+1,word,board,nx,ny,r,c,visited)){
                    return true ;
                }
            visited[i][j] = false ;
                
            }
        
        }
        return false ;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false)) ;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(board[i][j] == word[0] && dfs_helper(1,word,board,i,j,r,c,visited)){
                    return true;
                }
            }
        }
        return false;
        /*
        Time : O(N*M*4^L)
        Space : O(N*M)
        */
    }
};


int main() {
/**/
return 0;
}