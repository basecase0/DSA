/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
*/

bool comp(string& s1,string& s2){
    return s1.size()<s2.size();
}
class Solution {
public:
    bool checkPossible(string& s1,string& s2){
        if(s1.size()!=s2.size()+1) return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);   // sort on basis of length.
        int ans=1;
        vector<int>dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkPossible(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};