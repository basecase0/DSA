#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));    // 2d array space optimization
        vector<vector<int>> curr(2,vector<int>(k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int t=1;t<=k;t++){
                    if(buy){
                        curr[buy][t]=max(-prices[i]+ahead[0][t],ahead[1][t]);
                    }
                    else{
                        curr[buy][t]=max(prices[i]+ahead[1][t-1],ahead[0][t]);
                    }
                }
                ahead=curr;
            }
        }
        return ahead[1][k];

        // 1D array space optimization
        
        // vector<int>ahead(2*k+1,0);
        // vector<int>curr(2*k+1,0);
        
        // // Tabulation
        // for(int i=n-1;i>=0;i--){
        //     for(int transactions=2*k-1;transactions>=0;transactions--){
                
        //         if(transactions%2==0){          // Can Buy
        //             curr[transactions]=max(-prices[i]+ahead[transactions+1],ahead[transactions]);
        //         }
        //         else{       // Cannot Buy
        //             curr[transactions]=max(prices[i]+ahead[transactions+1],ahead[transactions]);
        //         }
        //     }
        //     ahead=curr;
        // }
        // return ahead[0];
        
    }
};

class Solution {
  public:
    int helper(int i,int transactions,int A[],int size,int cap,vector<vector<int>>& dp){
        if(i==size || transactions==2*cap) return 0;
        
        if(dp[i][transactions]!=-1) return dp[i][transactions];
        
        if(transactions%2==0){          // Can Buy
            dp[i][transactions]=max(-A[i]+helper(i+1,transactions+1,A,size,cap,dp),helper(i+1,transactions,A,size,cap,dp));
        }
        else{       // Cannot Buy
            dp[i][transactions]=max(A[i]+helper(i+1,transactions+1,A,size,cap,dp),helper(i+1,transactions,A,size,cap,dp));
        }
        return dp[i][transactions];
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(2*K+1,0));
        // return helper(0,0,A,N,K,dp);
        
        // Tabulation
        for(int i=N-1;i>=0;i--){
            for(int transactions=2*K-1;transactions>=0;transactions--){
                
                if(transactions%2==0){          // Can Buy
                    dp[i][transactions]=max(-A[i]+dp[i+1][transactions+1],dp[i+1][transactions]);
                }
                else{       // Cannot Buy
                    dp[i][transactions]=max(A[i]+dp[i+1][transactions+1],dp[i+1][transactions]);
                }
            }  
        }
        return dp[0][0];
        
    }
};