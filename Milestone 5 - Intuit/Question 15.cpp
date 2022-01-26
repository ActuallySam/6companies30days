#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/koko-eating-bananas/
*/
bool ispossible(vector<int> piles,int h,int capacity){
        int h_pos = 0;
        for(int i = 0;i<piles.size();i++){
            h_pos += piles[i]/capacity + (piles[i]%capacity != 0);
        }
        if(h_pos<=h){
            return true;
        }
        return false ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ma_val = INT_MIN ;
        
        for(int i = 0;i<piles.size();i++){ 
            ma_val = max(ma_val,piles[i]) ;
        }
        int low = 1 ;
        int high = ma_val ;
        int ans = INT_MAX ;
        while(low<=high){
            int mid = low+(high-low)/2 ;
            if(ispossible(piles,h,mid)){
                ans = mid ;
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans ;
        /*
        Time :O(N*logn)
        Space : O(1)
        */
    }
int main() {
/**/
return 0;
}