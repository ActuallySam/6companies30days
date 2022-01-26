#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/as-far-from-land-as-possible/
*/
bool isvalid(int x,int y,int n,vector<vector<int>>& grid){
    //function for checking wether co-ordinates are valid or not
    return (x>=0 && y>=0 && x<n && y<n && !grid[x][y]);
    
}
int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q ;
        int n = grid.size() ;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        //if everything is 0 are everything is 1
        if(q.size() == 0 || q.size() == n*n) return -1;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        
        //multi source bfs
        int ans = 0;
        
        while(q.size()!=0){
            int s = q.size() ;
            for(int i = 0;i<s;i++){
                auto t = q.front() ;
                int x = t.first ;
                int y = t.second ;
                q.pop();
                for(int j = 0;j<4;j++){
                    int nx = x+dx[j] ;
                    int ny = y+dy[j] ;
                    if(isvalid(nx,ny,n,grid)){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            if(q.size()!=0){
                ans++;
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