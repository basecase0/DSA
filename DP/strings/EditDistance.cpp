#include<bits/stdc++.h>
using namespace std;
/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

class Solution {
public:
    int helper(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
        
        if(j==0){
            return i;
        }
        if(i==0){
            return j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int minans=0;

        if(word1[i-1]==word2[j-1]){
            return dp[i][j]=helper(i-1,j-1,word1,word2,dp);
        }
        else{
            int ins=helper(i,j-1,word1,word2,dp);
            int del=helper(i-1,j,word1,word2,dp);
            int rep=helper(i-1,j-1,word1,word2,dp);
            minans=min(ins,min(del,rep));
        }
        return dp[i][j]=1+minans;

    }
    int minDistance(string word1, string word2) {
        // f(i,j)  means convert s1[0...i] to s2[0...j]
        // if match i-1,j-1 
        // else  min(replace,insert,delete)

        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(n,m,word1,word2,dp);

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];

    }
};