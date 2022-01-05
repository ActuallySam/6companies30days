class Solution {
    
    public int countSubArrayProductLessThanK(long a[], long n, long k)
    {
        long prod = 1;
        int j = 0, ans = 0;
        
        for(int i=0; i<n; i++){
            prod = prod * a[i];
            while(j < n && prod >= k){
                prod = prod / a[j];
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
}