#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
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
        long long int m =  1e9+7 ;
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    // if(t[i-1][j-arr[i-1]] ){
                    //     t[i][j]=1+t[i-1][j];
                    // }
                    // // if(t[i-1][j] && t[i-1][j-arr[i-1]]){
                    // //     t[i][j]=1+max(t[i-1][j] , t[i-1][j-arr[i-1]]);
                    // // }
                    // else{
                    //     t[i][j]=max(t[i-1][j] , t[i-1][j-arr[i-1]]);
                    // }
                    t[i][j]=t[i-1][j]%m + t[i-1][j-arr[i-1]]%m;
                }
                else{
                    t[i][j]=t[i-1][j]%m;
                }
            }
        }
        
        return t[n][sum]%m;
	}
	  
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends