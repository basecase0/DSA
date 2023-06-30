#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int requireTime(vector<int>piles,int k,int h){
        int totalTime=0;
        for(int i=0;i<piles.size();i++){
            // totalTime+=(ceil((double)piles[i]/(double)k));
            if(totalTime>h) return INT_MAX;
            int rem=piles[i]/k;
            totalTime+=rem;
            if(piles[i]%k!=0) totalTime++;
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxe=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]>maxe){
                maxe=piles[i];
            }
        }
        int low=1,high=maxe;
        while(low<=high){
            int k=(low+high)/2;
            int rTime=requireTime(piles,k,h);

            if(rTime<=h){
                high=k-1;
            }
            else{
                low=k+1;
            }
        }
        return low;
    }
};