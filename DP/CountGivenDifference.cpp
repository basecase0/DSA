/*
Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d. since the answer may be large return it modulo 109 + 7.
*/

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        long long int m=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        if((sum-d)%2!=0 || d>sum){
            return 0;
        }
        sum=(sum-d)/2;   // only till we want.
        int t[n+1][sum+1];
        
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=(t[i-1][j]%m + t[i-1][j-arr[i-1]]%m)%m;
                }
                else{
                    t[i][j]=t[i-1][j]%m;
                }
            }
        }
        // int s2=(sum-d)/2;
        
        return t[n][sum]%m;   // i==n
    }
};