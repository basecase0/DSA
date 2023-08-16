class Solution {
public:
    int climbHelper(int n,vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int path1=climbHelper(n-1,dp);
        int path2=climbHelper(n-2,dp);
        int total=path1+path2;
        dp[n]=total;

        return total;
    }
    int climbStairs(int n) {
        
        vector<int>dp(n+1,0);
        // return climbHelper(n,dp);     // memoization

        // Tabulation
        dp[0]=1;    // initialization.
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};