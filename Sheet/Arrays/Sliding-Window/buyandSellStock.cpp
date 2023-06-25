#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int op=0;
        int pist=0;
        int lsf=INT_MAX;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<lsf){
                lsf=prices[i];
            }
            pist=prices[i]-lsf;
            if(pist>op){
                op=pist;
            }
        }
        return op;
    }
};

//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int op=0;
        int left=0,right=1;
        while(right<=prices.size()-1){
            if(prices[left]<prices[right]){
                if((prices[right]-prices[left])>op){
                    op=prices[right]-prices[left];
                }
            }
            else{
                left=right;
            }
            right++;
        }
        return op;
    }
};