/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/

// detect cycle.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        int slow2=0;
        while(true){
            slow=nums[slow];
            slow2=nums[slow2];
            if(slow==slow2) return slow;
        }
    }
};