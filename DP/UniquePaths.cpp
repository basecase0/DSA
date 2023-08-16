class Solution {
public:
    int helper(int chR,int chD,int m,int n,vector<vector<int>>&dp){
        if(chR>=m && chD>=n){
            return 1;
        }
        if(dp[chR][chD]!=-1){
            return dp[chR][chD];
        }
        int ch1=0,ch2=0;
        if(chR<m){
            ch1=helper(chR+1,chD,m,n,dp);
        }
        if(chD<n){
            ch2=helper(chR,chD+1,m,n,dp);
        }
        return dp[chR][chD]=(ch1+ch2);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        // return helper(0,0,m-1,n-1,dp);
        // dp[m][n]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};