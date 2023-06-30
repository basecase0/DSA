#include <bits/stdc++.h>
using namespace std;

// windowSize-maxfreq<=k

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mmap(256,0);
        int left=0,right=0;
        int maxfreq=0;
        int len=0;
        while(right<s.length()){
            mmap[s[right]]++;
            if(mmap[s[right]]>maxfreq){
                maxfreq=mmap[s[right]];
            }
            int windsize=right-left+1;
            
            if(windsize-maxfreq>k){
                mmap[s[left]]--;
                left++;
            }
            len=max((right-left+1),len);
            right++;
            
        }
        return len;
    }
};