class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            // int coin=coins[i];
            for(int j=1;j<amount+1;j++){
                if(coins[i]<=j){
                    dp[j]+=dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};