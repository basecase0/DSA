/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution {

    void bfs(queue<pair<int,int>> q,vector<vector<int>>& heights,vector<vector<int>>& vis){
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            int n=heights.size();
            int m=heights[0].size();

            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                heights[nrow][ncol]>=heights[r][c]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        queue<pair<int,int>> pac;        
        queue<pair<int,int>> atl;
       
        vector<vector<int>>vispac(n,vector<int>(m,0));  // if 1 water flow to pacific from that cell.
        vector<vector<int>>visatl(n,vector<int>(m,0));

        for(int i=0;i<n;i++){           // push all the borders.
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    pac.push({i,j});
                    vispac[i][j]=1;
                }
                if(i==n-1 || j==m-1){
                    atl.push({i,j});
                    visatl[i][j]=1;
                }
            }
        }

        bfs(pac,heights,vispac);
        bfs(atl,heights,visatl);
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vispac[i][j] && visatl[i][j]){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};