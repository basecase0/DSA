/**
 You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

*/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;  // {{r,c},t}
        int vis[n][m];

        // push all rotten oranges as starting vertex to queue.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int tm=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;      // read
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();        // remove 
            tm=max(tm,t);
            // check four sides
            for(int i=0;i<4;i++){
                int newrow=r+delrow[i];
                int newcol=c+delcol[i];

                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]!=2
                && grid[newrow][newcol]==1){
                    vis[newrow][newcol]=2;
                    q.push({{newrow,newcol},tm+1});  // increment time.  // push
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){  // if fresh orange still remains.
                    return -1;
                }
            }
        }
        return tm;
    }
};