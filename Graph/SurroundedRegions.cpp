/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
*/

class Solution {
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=-1;

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && 
            vis[nrow][ncol]!=-1){
                
                dfs(nrow,ncol,board,vis);
            }
        }

    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O'){
                    dfs(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]!=-1){
                    board[i][j]='X';
                }
            }
        }
    }
};