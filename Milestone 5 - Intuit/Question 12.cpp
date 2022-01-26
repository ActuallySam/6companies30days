#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/course-schedule-ii/ 
*/
class Solution {
    /*
    Just finding the order of the courses 
    //using khans algorithm
    */
private:
    vector<int> toposort(vector<int> adj[],int n){
        //calucalte indegree
        vector<int>indegree(n,0),ans ;
        
        for(int i = 0;i<n;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q ;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.size()!=0){
            int node = q.front() ;
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans ;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        //constucting graph
        vector<int> adj[n] ;
        for(int i = 0;i<preq.size();i++){
            adj[preq[i][1]].push_back(preq[i][0]) ;
        }
        vector<int>ans =  toposort(adj,n);
        if(ans.size() == n){
            return ans ;
        }
        return {};
        /*
        Time : O(V+E)
        Space : O(V)
        */
    }
};
int main() {
/**/
return 0;
}