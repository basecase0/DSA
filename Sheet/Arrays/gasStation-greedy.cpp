#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int curr=0;
        int totalgas=0,totalcost=0;
        int start=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        if(totalgas<totalcost){
            return -1;
        }
        return start;
    }
};