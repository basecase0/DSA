/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& newvis,vector<vector<int>>& image,
    int px,int newColor){
        
        newvis[row][col]=newColor;
        vis[row][col]=1;
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(delrow==delcol || (delrow==-delcol)){
                        continue;
                    }
                    int nrow=r+delrow;
                    int ncol=c+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==px){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                        newvis[nrow][ncol]=newColor;
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int px=image[sr][sc];
        
        vector<vector<int>>newvis=image;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        bfs(sr,sc,vis,newvis,image,px,newColor);
         
        return newvis;
    }
};

// Leetcode solution:

class Solution {
    void dfs(int r,int c,int color,vector<vector<int>>& image,vector<vector<int>>& vis){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=image.size();
        int m=image[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            image[nrow][ncol]==color){
                dfs(nrow,ncol,color,image,vis);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        dfs(sr,sc,image[sr][sc],image,vis);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    vis[i][j]=color;
                }
                else{
                    vis[i][j]=image[i][j];
                }
            }
        }
        return vis;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends