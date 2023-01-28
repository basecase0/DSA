#include<bits/stdc++.h>
using namespace std;
// 42. Trapping rain Water - two pointer approach
class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int left=0,right=height.size()-1,leftmax=0,rightmax=0;
        int i=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftmax<=height[left]) leftmax=height[left];
                else res+=leftmax-height[left];
                left++;
            }
            else{
                if(height[right]>=rightmax) rightmax=height[right];
                else res+=rightmax-height[right];
                right--;
            }
        }
        return res;
    }
};