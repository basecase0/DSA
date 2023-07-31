#include<bits/stdc++.h>
using namespace std;

class Solution
{
    // int t[1002][10002];
    // memset(t,-1,sizeof(t));
    
    public:
    int memoizationDP(int W, int wt[], int val[], int n,vector<vector<int>>&t){
        if(n==0 || W==0){
           return 0;
       }
       if(t[n][W]!=-1){
           return t[n][W];
       }
       
       if(wt[n-1]<=W){
           t[n][W]=max((val[n-1]+memoizationDP(W-wt[n-1],wt,val,n-1,t)),memoizationDP(W,wt,val,n-1,t));
           return t[n][W];
       }
       else{
           t[n][W]=memoizationDP(W,wt,val,n-1,t);
           return t[n][W];
       }
    }
    
    int tabulationDP(int W, int wt[], int val[], int n){     // n->i   W->j
        int t[n+1][W+1];
       
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 || j==0){
                   t[i][j]=0;
               }
           }
       }
       
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               
               if(wt[i-1]<=j){
                   t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]), t[i-1][j]);
               }
               else{
                   t[i][j]=t[i-1][j];
               }
           }
       }
       return t[n][W];
    }

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>> t(n+1,vector<int>(W+1,-1));
       return memoizationDP(W,wt,val,n,t);
    }
};

//{ Driver Code Starts.
int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends