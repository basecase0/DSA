class Solution {
public:
    int helper(int i,int buy,int transactions,vector<int>& prices,vector<vector<vector<int>>>& dp){

        if(i==prices.size()) return 0;
        if(transactions==0) return 0;

        if(dp[i][buy][transactions]!=-1) return dp[i][buy][transactions];


        if(buy){
            dp[i][buy][transactions]=max(-prices[i]+helper(i+1,0,transactions,prices,dp), 
                helper(i+1,buy,transactions,prices,dp));
        }
        else{
            dp[i][buy][transactions]=max(prices[i]+helper(i+1,1,transactions-1,prices,dp),
                helper(i+1,0,transactions,prices,dp));
        }
        return dp[i][buy][transactions];
    }

    int maxProfit(vector<int>& prices) {

        vector<vector<vector<int>>>dp (prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

        // return helper(0,1,2,prices,dp);
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int transactions=1;transactions<=2;transactions++){
                    if(buy){
                        dp[i][buy][transactions]=max(-prices[i]+dp[i+1][0][transactions],
                        dp[i+1][1][transactions]);
                    }
                    else{
                        dp[i][buy][transactions]=max(prices[i]+dp[i+1][1][transactions-1],
                        dp[i+1][0][transactions]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};