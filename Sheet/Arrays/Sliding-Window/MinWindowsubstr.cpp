#include<bits/stdc++.h>
using namespace std;

// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".



class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>map_t;
        int m=s.length();
        int n=t.length();
        for(int i=0;i<n;i++){
            map_t[t[i]]++;
        }
        int left=0,right=0;
        string ans="";
        int anslen=INT_MAX;
        int mct=0,dmct=n;   // desired match count is length of string t.
        int i=0;
        unordered_map<char,int>map_s;

        while(true){
            bool f1=false,f2=false;
            // acquire
            while(right<m && mct<dmct){
                map_s[s[right]]++;
                if(map_s[s[right]]<=map_t[s[right]]){
                    mct++;      // the char acquired is correct
                }
                right++;
                f1=true;
            }
            
            // collect ans and release
            while(i<right && mct==dmct){
                // string pans=s.substr(left,right-i);
                int panslen=right-i;
                // cout<<pans<<endl;
                if(panslen<anslen){
                    anslen=panslen;
                    left=i;
                }
                map_s[s[i]]--;
                if(map_s[s[i]]<map_t[s[i]]){
                    mct--;
                }
                i++;
                f2=true;
            }

            if(f1==false && f2==false){
                break;
            }

        }
        return anslen==INT_MAX? "" : s.substr(left,anslen);
        
    }
};