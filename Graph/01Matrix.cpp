class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        // Graph approach
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> bfs;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    bfs.push({{i,j},0});
                }
            }
        }

        vector<vector<int>>ans(m,vector<int>(n,0));

        while(!bfs.empty()){
            int r=bfs.front().first.first;
            int c=bfs.front().first.second;
            int step=bfs.front().second;

            bfs.pop();

            ans[r][c]=step;

            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newr=r+delrow[i];
                int newc=c+delcol[i];

                if(newr>=0 && newr<m && newc>=0 && newc<n && mat[newr][newc]==1 && 
                !vis[newr][newc]){
                    vis[newr][newc]=1;
                    bfs.push({{newr,newc},step+1});
                }
            }
        }
        return ans;
    }
};