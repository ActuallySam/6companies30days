#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
link : https://leetcode.com/problems/find-in-mountain-array/
*/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
int binary_search_desc(MountainArray &arr,int low,int high,int target){
        //binarysearch for descending order
        while(low<=high){
            int mid = low + (high-low)/2 ;
            int curr = arr.get(mid);
            if(curr == target){
                return mid;
            }
            else if(curr<target){
                high = mid-1;
            }
            else{
                low = mid+1 ;
            }
        }
        return -1 ;
        /*
        Time : O(Logn)
        Space : O(1)
        */
    }
int binary_search_asc(MountainArray &arr,int low,int high,int target){
        //binarysearch for ascending order
        while(low<=high){
            int mid = low + (high-low)/2 ;
            int curr = arr.get(mid) ;
            if(curr == target){
                return mid ;
            }
            else if(curr<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
        /*
        Time : O(logn)
        Space : O(1)
        */
        
    }
int peakelement(MountainArray &arr,int low,int high,int n){
        //finding peak element (maximum element)
        int index = -1;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(mid>0 && mid<(n-1)){
                int prev = arr.get(mid-1);
                int next = arr.get(mid+1);
                int curr = arr.get(mid) ;
                if(prev<curr && curr>next){
                    index = mid ;
                    break ;
                }
                else if(prev>curr){
                    high = mid-1;
                }
                else{
                    low = mid+1 ;
                }
                
            }
            else{
                if(mid == 0){
                    if(arr.get(0)> arr.get(1)){
                        return 0;
                    }
                    else{
                        return 1 ;
                    }
                    
                }
                else{
                    if(arr.get(n-1)>arr.get(n-2)){
                        return n-1;
                    }
                    else{
                        return n-2;
                    }
                    
                }
                
            }
        }
        return index ;
        /*
        Time : O(Logn)
        Space : O(1)
        */
        
    }
    int findInMountainArray(int target, MountainArray &arr) {
        
        int n = arr.length();
        int ind = peakelement(arr,0,n-1,n);
        int left = binary_search_asc(arr,0,ind,target) ;
        int right = binary_search_desc(arr,ind+1,n-1,target) ;
        if(left == -1){
            return right ;
        }
        return left ;

        /*
        Time : O(Logn)
        Space : O(1)
        */
        
    }
int main() {
/**/
return 0;
}