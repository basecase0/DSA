class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>hash(n,1);  // to trace back
        vector<int>dp(n,1);
        int maxlen=0,lastidx=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxlen){
                maxlen=dp[i];
                lastidx=i;
            }
        }
        ans.push_back(nums[lastidx]);  // trace from lastidx(index with maxlen).
        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        return ans;
    }
};