class Solution {
    static int findPosition(int N , int M , int K) {
        // code here
        // K -> given position
        // M -> items to be distributed
        // N -> size of the circle
        
        // (N - K + 1) is number of positions before we reach 
        // beginning of circle. If m is less than this value, 
        // then we can simply return (M-1)th position
        if (M <= N - K + 1) 
            return M + K - 1;
        
        // remaining M items calculation
        M = M - (N - K + 1);
        
        // if (M%N) will be 0, then we can return the size of the 
        // circle which means that the circle was entirely filled with all the 
        // slots it had, which is N.
        // Otherwise it will return the (M%N) which denotes the slot that 
        // got filled last and give the position of it
        return (M % N == 0) ? N : (M % N);
        
    }
};