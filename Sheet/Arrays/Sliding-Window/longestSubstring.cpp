class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int left=0,right=0;
        vector<int> mmap(256,-1);  // 
        while(right<s.length()){
            if(mmap[s[right]]!=-1){
                left=max(mmap[s[right]]+1,left);
            }
            mmap[s[right]]=right;
            len=max(right-left+1,len);
            right++;
        }
        return len;
    }
};