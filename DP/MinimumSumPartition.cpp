/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.
*/

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
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
	    vector<int> s1;
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	            if(arr[i-1]<=j){
	                t[i][j]=max(t[i-1][j],t[i-1][j-arr[i-1]]);
	            }
	            else{
	                t[i][j]=t[i-1][j];
	            }
	            
	            if(i==n && j<(sum/2 +1) && t[i][j]==1){
	            s1.push_back(j);
	        }
	        }
	        
	    }
	    
	    int sz=s1.size();
	    if(sz==0) return sum;
	   // cout<<sz<<endl;
	    return sum-2*s1[sz-1] ;
	    
	    
	} 
};