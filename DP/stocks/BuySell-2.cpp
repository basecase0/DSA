/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

class Solution {
public:
    int helper(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];


        if(buy){
            dp[i][buy]=max(-prices[i]+helper(i+1,0,prices,dp), helper(i+1,buy,prices,dp));
        }
        else{
            dp[i][buy]=max(prices[i]+helper(i+1,1,prices,dp), helper(i+1,0,prices,dp));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));

        // return helper(0,1,prices,dp);
        int n=prices.size();
        dp[n][0]=0,dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){                  // Can buy -> buy or not
                    dp[i][j]=max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                else{                  // Cannot buy -> sell or not
                    dp[i][j]=max(prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};