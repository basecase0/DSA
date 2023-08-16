class Solution {
public:
    int helper(int chR,int chD,int m,int n,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(chR==m && chD==n){
            return grid[m][n];
        }
        if(dp[chR][chD]!=-1){
            return dp[chR][chD];
        }
        int ch1=0,ch2=0;
        if(chR==m) return dp[chR][chD]=helper(chR,chD+1,m,n,dp,grid)+grid[chR][chD];

        if(chD==n) return dp[chR][chD]=helper(chR+1,chD,m,n,dp,grid)+grid[chR][chD];
        
        if(chR<m){
            ch1=helper(chR+1,chD,m,n,dp,grid);
        }
        if(chD<n){
            ch2=helper(chR,chD+1,m,n,dp,grid);
        }
        return dp[chR][chD]=min(ch1,ch2)+grid[chR][chD];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return helper(0,0,m-1,n-1,dp,grid);
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j]=grid[i][j];
                else if(i==m-1){
                    dp[i][j]=dp[i][j+1]+grid[i][j];
                } 
                else if(j==n-1){
                    dp[i][j]=dp[i+1][j]+grid[i][j];
                }
                else{
                    dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};