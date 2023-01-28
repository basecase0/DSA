#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        int ngetr[n];
        int span[n];
        int last=prices[n-1];
        ngetr[n-1]=last;
        st.push(last);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<prices[i]){
                st.pop();
            }
            if(st.empty()){
                ngetr[i]=prices[i];
            }
            else{
                ngetr[i]=st.top();
            }
            st.push(prices[i]);
        }

        for(int i=0;i<n;i++){
            span[i]=ngetr[i]-prices[i];
        }
        int max=0;
        for(int i=0;i<n;i++){
            if(span[i]>max){
                max=span[i];
            }
        }
        return max;
    }
};