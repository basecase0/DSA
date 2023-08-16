
int maxPoints(vector<vector<int>> &points,int idx,int last,vector<vector<int>>&dp){   // n-1 to 0  recursion. tabulation
    if(idx==0){    // day 0
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[idx][last]!=-1) return dp[idx][last];
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
           maxi=max(maxi,points[idx][i]+maxPoints(points, idx-1,i,dp));
       } 
    }
    return dp[idx][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
   vector<vector<int>>dp(n,vector<int>(4,0));
    // return maxPoints(points,n-1, 3,dp);
    // memoization
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));

    for(int i=1;i<n;i++){
        for(int last=0;last<4;last++){
            
            for(int task=0;task<=2;task++){
                if(task!=last){
                    dp[i][last]=max(dp[i][last],points[i][task]+dp[i-1][task]);
                } 
            }
            
        }
    }
    return dp[n-1][3];

    // space optimization
    vector<int>prevdp(4,0);
    prevdp[0]=max(points[0][1],points[0][2]);
    prevdp[1]=max(points[0][0],points[0][2]);
    prevdp[2]=max(points[0][0],points[0][1]);
    prevdp[3]=max(points[0][1],max(points[0][2],points[0][0]));

    for(int i=1;i<n;i++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            for(int task=0;task<=2;task++){
                if(task!=last){
                    temp[last]=max(temp[last],points[i][task]+prevdp[task]);
                } 
            }
            
        }
        prevdp=temp;
    }
    return prevdp[3];

}