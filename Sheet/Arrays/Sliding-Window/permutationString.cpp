#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        unordered_map<char,int> ms1;
        unordered_map<char,int> ms2;
        for(int i=0;i<s1.length();i++){
            ms1[s1[i]]++;
            ms2[s2[i]]++;
        }
        int matches=0;
        for(char i='a';i<='z';i++){
            if(ms1[i]==ms2[i]) matches++;

        }

        int left=0,right=s1.length(),len=0;     // window size is equal to s1.length
        while(right<s2.length()){
            if(matches==26){
                return true;
            }
            ms2[s2[right]]++;   // sliding window right
            if(ms1[s2[right]]==ms2[s2[right]]){
                matches++;
            }
            else if(ms1[s2[right]]+1==ms2[s2[right]]){
                matches--;
            }

            ms2[s2[left]]--;   // sliding window left
            if(ms1[s2[left]]==ms2[s2[left]]){
                matches++;
            }
            else if(ms1[s2[left]] - 1==ms2[s2[left]]){
                matches--;
            }
            right++;
            left++;
        }

        
        return (matches==26);
    }
};