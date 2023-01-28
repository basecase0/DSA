#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid,vector<int> positions,int c){
	int place=1;
	int coor=positions[0];
	for(int j=1;j<positions.size();j++){
		if(positions[j]-coor>=mid){
			place++;
			coor=positions[j];
		}
		if(place==c) return true;
		
	}
	
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int low=1;   // min diff distance 
	int high=positions[n-1]-positions[0];   // max distance
	int res=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(isPossible(mid,positions,c)){
			res=mid;
			low=mid+1;   // find max diastance
		}
		else{
			high=mid-1;
		}
	}
	return res;
}

int main(){
    return 0;
}