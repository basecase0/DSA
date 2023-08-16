class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<amount+1;j++){
                if(j==coins[i]){
                    dp[j]=1;
                }
                else if(dp[j-coins[i]]==0){
                    continue;
                }
                else{
                    if(dp[j]==0){
                        dp[j]=dp[j-coins[i]]+1;
                    }
                    else{
                        dp[j]=min(dp[j-coins[i]]+1,dp[j]);
                    }
                }
            }
        }
        return (dp[amount]==0 ? -1: dp[amount]);
    }

};