#include <bits/stdc++.h>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

//  1. same or ? -> i-1,j-1    2. * -> max(i-1,j or i,j-1)   3. false 
class Solution {
public:
    int helper(int i,int j,string& s,string& p,vector<vector<int>>& dp){

        if(i==0 && j==0){
            return true;
        }
        else if(j==0){
            return false;
        }
        else if(i==0){
            // true only if remaining p all *'s
            for(int m=1;m<=j;m++){
                if(p[m-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j]=helper(i-1,j-1,s,p,dp);
        }
        else if(p[j-1]=='*'){ 
            return dp[i][j]=helper(i,j-1,s,p,dp) | helper(i-1,j,s,p,dp);
        }
        else{
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // f(i,j) 
        // ?
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(n,m,s,p,dp);

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        dp[0][0]=1; // true
        for(int j=1;j<=m;j++){
            int flag=1;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=0;
                    break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];

    }
};