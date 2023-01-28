//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N){
            return -1;
        }
        int low=A[0];
        int high=0;
        for(int i=0;i<N;i++){
            if(A[i]<low){
                low=A[i];
            }
            high+=A[i];
        }
        int totalp=high;
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;    // max bar.
            int k=1;    // allocated to students.
            int currpages=0;
            for(int i=0;i<N;i++){
                if(A[i]>mid){
                    k=M+1;
                    break;
                }
                
                if(currpages+A[i]<=mid){
                    currpages+=A[i];
                }
                else{
                    k++;
                    currpages=A[i];
                }
            }
            if(k>M){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends