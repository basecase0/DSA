#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i,int previdx,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()) return 0;

        if(dp[i][previdx+1]!=-1) return dp[i][previdx+1];

        if(previdx==-1 || nums[i]>nums[previdx]){
            return dp[i][previdx+1]=max(1+helper(i+1,i,nums,dp) , helper(i+1,previdx,nums,dp));
        }
        else{
            return dp[i][previdx+1]=helper(i+1,previdx,nums,dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        // return helper(0,-1,nums,dp);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                if(j==-1 || nums[i]>nums[j]){
                    dp[i][j+1]=max(1+dp[i+1][i+1] , dp[i+1][j+1]);      // second parameter +1.
                }
                else{
                    dp[i][j+1]=dp[i+1][j+1];
                }
            }
        }
        return dp[0][-1+1];

        // 1D dp
        int res=1;
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;

        //
        int lengthOfLIS(vector<int>& nums) {
        // Binary Search lower bound O(n logn)
        vector<int>temp;
        temp.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                // find first idx in temp with whihc to replace
                int newi=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[newi]=nums[i];
            }
        }
        return temp.size();
    }
    }
};