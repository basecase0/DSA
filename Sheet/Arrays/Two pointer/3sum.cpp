class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());  // sort
        int n=nums.size();
        int a=0;     // a+b+c=0
        vector<vector<int>>ans;
        while(a<nums.size()-2){
            if(a==0 || (a>0 && nums[a]!=nums[a-1])){
                int l=a+1;
                int h=n-1;
                int sum=0-nums[a];
                while(l<h){
                    if(nums[l]+nums[h]==sum){
                        vector<int> temp;
                        temp.push_back(nums[a]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        
                        ans.push_back(temp);
                        while(l<h && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<h && nums[h]==nums[h-1]){
                            h--;
                        }
                        l++;
                        h--;
                    }
                    else if(nums[l]+nums[h]< sum){
                        l++;
                    }
                    else{
                        h--;
                    }
                }
            }
            a++;
        }
        return ans;
    }
};