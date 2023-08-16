class Solution {
public:
    int helper(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            return nums[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=max(nums[i]+helper(i+2,nums,dp) , helper(i+1,nums,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        // return helper(0,nums,dp);

        // dp[n-1]=nums[n-1];  // memoization
        // if(n==1){
        //     return dp[0];
        // }
        // dp[n-2]=max(nums[n-1],nums[n-2]);
        // for(int i=n-3;i>=0;i--){
        //     dp[i]=max(nums[i]+dp[i+2] , dp[i+1]);
        // }
        // return dp[0];
        int next=nums[n-1];
        if(n==1) return nums[0];
        int next2=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){
            int curri=max(nums[i]+next , next2);
            next=next2;
            next2=curri;
            
            // prevcurri;
        }
        return next2;
    }
};