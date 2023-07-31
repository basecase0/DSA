/*
658. Find K Closest Elements
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            int diff=abs(x-arr[i]);
            // cout<<diff<<" ";
            pq.push(make_pair(diff,arr[i]));
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        // priority_queue<int,vector<int>,greater<int>> sec;
        // int i=0;
        while(pq.size()>0){
            int num=pq.top().second;
            cout<<num<<" ";
            ans.push_back(num);
            pq.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};