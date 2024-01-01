/*
115.
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/

class Solution {
    int helper(string s,string t,int i,int j,vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=helper(s,t,i-1,j-1,dp)+helper(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j]=helper(s,t,i-1,j,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // memo
        // return helper(s,t,n-1,m-1,dp);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};