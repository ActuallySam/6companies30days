#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
*/
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
bool isvalid(int x,int y,int n, int m,vector<vector<bool>> grid,vector<vector<int>>& temp,int prev){
    return (x>=0 && y>=0 && x<n && y<m && !grid[x][y] && temp[x][y]>=prev) ;
}
void dfs(int x,int y,int n,int m,vector<vector<bool>>& grid,vector<vector<int>>&temp,int prev){
        grid[x][y] = true ;
        for(int i = 0;i<4;i++){
            int nx = x+dx[i] ;
            int ny = y+dy[i] ;
            if(isvalid(nx,ny,n,m,grid,temp,temp[x][y])){
                dfs(nx,ny,n,m,grid,temp,temp[x][y]) ;
            }
        }
        return ;
    }


void dfs_2(int x,int y,int n,int m,vector<vector<bool>>& grid,vector<vector<int>>&temp,int prev){
    if(x<0 || y<0 || x>=n || y>=m || temp[x][y]<prev){
        return ;
    }
    if(grid[x][y]){
        return ;
    }
    grid[x][y] = true;
    
    for(int i = 0;i<4;i++){
        dfs(x+dx[i],y+dy[i],n,m,grid,temp,temp[x][y]) ;
    }   
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
    int n = heights.size() ;
    int m = heights[0].size() ;
    vector<vector<bool>> pac(n,vector<bool>(m,false)),atl(n,vector<bool>(m,false)) ;
        
    for(int i = 0;i<n;i++){
           dfs(i,0,n,m,pac,heights,-1);
       }
        
    for(int j = 0;j<m;j++){
           dfs(0,j,n,m,pac,heights,-1);
       }
        
    for(int i = 0;i<n;i++){
            dfs(i,m-1,n,m,atl,heights,-1);
        }
        
    for(int j = 0;j<m;j++){
            dfs(n-1,j,n,m,atl,heights,-1);
        }
        
    vector<vector<int>> ans ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(pac[i][j] && atl[i][j]){
                ans.push_back({i,j});
            }
        }
    }
        return ans ;
        /*
        Time : O(N*N)
        Space : O(N)
        */
}

int main() {
/**/
return 0;
}