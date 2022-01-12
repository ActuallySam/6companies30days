class Solution
{
    public int CountWays(String str)
    {
        // code here
        int n = str.length();

        int[] dp = new int[n + 1];
        
        if(str.charAt(0) == '0')
        return 0;
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
        int c1 = 0, c2 = 0;
        
        if(str.charAt(i-1) > '0'){
        c1 = dp[i-1];
        }
        if(str.charAt(i-2) == '1' || (str.charAt(i-2) == '2' && str.charAt(i-1) < '7'))
        c2 = dp[i-2];
        
        dp[i] = (c1+c2)%1000000007;
        }
        
        return dp[n];
    }
}