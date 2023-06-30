#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){
          int mid=low+(high-low)/2;
          if(nums[low]<nums[mid] && nums[mid]<nums[high]){
            return nums[low];
          }
          else if(nums[mid]>nums[high]){
              if(mid+1==high) return nums[high];
              low=mid;
          }
          else{ // nums[low]>nums[mid]
              if(low+1==mid){
                  return nums[mid];
              }
              high=mid;
          }
          
        }
        return nums[low]; 
    }
};