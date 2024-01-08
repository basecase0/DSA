/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int ans=1,res=0;

        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    count[i]=count[prev];
                }
                else if(nums[prev]<nums[i] && dp[i]==1+dp[prev]){
                    // same length
                    count[i]+=count[prev];
                }
            }
            ans=max(ans,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==ans) res+=count[i];
        }
        return res;
    }
};