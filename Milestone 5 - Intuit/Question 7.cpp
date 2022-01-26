#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

bool ispossible(vector<int> arr,int days,int mid){
        //function to check wether we can do do it given number of days or not
        int curr = 0;
        int n_d = 0 ;
        for(int i = 0;i<arr.size();i++){
            curr+=arr[i] ;
            if(curr>mid){
                curr = arr[i] ;
                n_d++;
            }
        }
        if(n_d<days){
            return true;
        }
        return false ;
}

int shipWithinDays(vector<int>& arr, int days) {
        int ma_val = INT_MIN ;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum = sum +arr[i] ;
            ma_val = max(ma_val,arr[i]) ;
        }
        int low = ma_val ;
        int high = sum ;
        int ans = INT_MAX ; ;
        while(low<=high){
            int mid = low+(high-low)/2 ;
            if(ispossible(arr,days,mid)){
                ans = mid ;
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans ;
        /*
        Time : O(N*logN)
        Space : O(1)
        */
}
int main() {
/**/
return 0;
}