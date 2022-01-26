#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/split-array-largest-sum/
*/
bool isvalid(vector<int> nums,int cap,int m){
        int splits = 0;
        int n = nums.size() ;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(sum+nums[i]<=cap){
                sum+=nums[i];
            }
            else{
                sum = nums[i] ;
                splits++;
            }
        }
        if((splits+1)>m){
            return false;
        }
        return true;
    }

int splitArray(vector<int>& nums, int m) {
        int n = nums.size() ;
        int ma_value = INT_MIN ;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i] ;
            ma_value = max(ma_value,nums[i]) ;
        }
        
        int low = ma_value ;
        int high = sum ;
        int res = -1;
        while(low<=high){
            int mid = low +(high-low)/2 ;
            if(isvalid(nums,mid,m)){
                res = mid ;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
        /*
        Time : O(N*logN)
        Space : O(1)
        */
        
    }
int main() {
/**/
return 0;
}