#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string,vector<pair<string,int>>> st;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        st[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(st.find(key)==st.end()){
            return "";
        }
        if(st[key][0].second > timestamp){
            return "";
        }
        string rt;
        int low=0;
        int high=st[key].size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(st[key][mid].second == timestamp){
                return st[key][mid].first;
            }
            else if(st[key][mid].second>timestamp){
                high=mid-1;
            }
            else{
                rt=st[key][mid].first;
                low=mid+1;
            }
        }
        return rt;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */