/*
347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

class Solution {
    typedef pair<int,int> pi;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto i:um){
            pq.push({i.second,i.first});  // frequency first int in pair.
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
