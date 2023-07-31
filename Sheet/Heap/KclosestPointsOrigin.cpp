/*
973. K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

class Solution {
 typedef pair<int,vector<int>> ppi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> pq;
        for(int i=0;i<points.size();i++){
            int dist=(points[i][0]*points[i][0]) +(points[i][1]*points[i][1]);     // x^2+y^2
            pair temp=make_pair(dist,points[i]);
            pq.push({temp});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            vector<int> t=pq.top().second;
            pq.pop();
            ans.push_back(t);
        }
        return ans;
    }
};