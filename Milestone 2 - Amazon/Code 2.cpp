//  Longest Mountain in Array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<int> upHill(n), downHill(n);
        for(int i = n-2; i>=0; i--){
            downHill[i] = arr[i] > arr[i+1] ? downHill[i+1] + 1 : 0;
        }
        
        for(int i = 1; i<n; i++){
            upHill[i] = arr[i] > arr[i-1] ? upHill[i-1] + 1 : 0;
        }
        
        for(int i = 0; i<n; i++){
            ans = (upHill[i] && downHill[i]) ? max(ans, upHill[i] + downHill[i] + 1) : ans;
        }
        return ans;
    }
};