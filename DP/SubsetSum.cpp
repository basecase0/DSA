#include<bits/stdc++.h>
using namespace std;

// subset sum - is a subset with sum given possible T/F.
// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

bool isSubsetSum(vector<int>arr, int sum){
    int n=arr.size();
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
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){  // 
                t[i][j]= max(t[i-1][j-arr[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/
bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    if(sum%2!=0){
        return false;
    }
    int target=sum/2;
    int t[n+1][target+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
                t[i][j]=max(t[i-1][j-nums[i-1]] , t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][target];
}

int main(){

    return 0;
}