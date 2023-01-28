#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int medianofsortedarrays(vector<int>nums1,vector<int>nums2){
        if(nums2.size()<nums1.size()) return medianofsortedarrays(nums2,nums1);  // nums1 as search space smaller n1. 
        int n1=nums1.size();  // nums1 should be smaller and cut1
        int n2=nums2.size();
        int low=0,high=n1;
        while(low<=high){
            int cut1=(low+high)/2;  // works for odd and even length.  // lefthalf if total length odd lefthhalf has one element more than righthalf
            int cut2=(n1+n2+1)/2-cut1;
            int l1= cut1==0?INT_MIN:nums1[cut1-1];      // edge cases
            int l2= cut2==0?INT_MIN:nums2[cut2-1];

            int r1= cut1==n1?INT_MAX:nums1[cut1];
            int r2= cut2==n2?INT_MAX:nums2[cut2];
            if(l1<= r2 && l2<=r1){  // check by crossing l1 with r2.
                // valid left and right half.
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                high=cut1-1;   // lefthalf of nums1
            }
            else{
                low=cut1+1;   // righthalf of nums1.
            }
        }
        return 0.0;
    }
};