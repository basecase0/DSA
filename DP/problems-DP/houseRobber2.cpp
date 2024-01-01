class Solution {
    int helper(vector<int>& nums,int start,int end){
        int prev2=0;
        int prev=0;

        for(int i=start;i<=end;i++){
            int curri=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) {
            return nums[0];
        }
        int ans1=helper(nums,0,n-2);
        int ans2=helper(nums,1,n-1);

        return max(ans1,ans2);
    }
};