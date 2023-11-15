#include <bits/stdc++.h>
using namespace std;

/* 
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
  private:
    void dfs(int node,int vis[],vector<vector<int>>& adj,int V){
        vis[node]=1;
        for(int i=0;i<V;i++){
            if(adj[node][i]==1 && vis[i]==0){
                dfs(i,vis,adj,V);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int vis[V]={0};
        int prov=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                prov++;
                dfs(i,vis,adj,V);
            }
        }
        return prov;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends