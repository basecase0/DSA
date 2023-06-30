#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<int> st;  // ngetr
        int n=nums.size();
        int ngetr[n];
        ngetr[n-1]=n;   // no ngetr store n
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[i]>nums[st.top()]){
                st.pop();
            }
            if(st.size()==0){
                ngetr[i]=n;     // no ngetr
            }
            else{
                ngetr[i]=st.top();
            }
            st.push(i);
        }
        vector<int>slidingMax(n-k+1);
        int j=0;
        for(int i=0;i<=n-k;i++){
            if(j<i){
                j=i;
            }
            while(ngetr[j]<i+k){
                j=ngetr[j];
            }
            slidingMax[i]=nums[j];
        }
        return slidingMax;

    }
};