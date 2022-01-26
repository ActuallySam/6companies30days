#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/number-of-provinces/
*/
int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> adj[n] ;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int compo = 0;
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                compo++;
                queue<int> q ;
                q.push(i);
                vis[i] = 1 ;
                while(q.size()!=0){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return compo ;
        /*
        Time : O(V+E)
        Space : O(V+E) + O(V)
        */
}
int main() {
/**/
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}} ;
    cout<<findCircleNum(isConnected)<<endl;
return 0;
}