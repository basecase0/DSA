//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool detect(int src,vector<int>& vis,vector<int> adj[]){    // BFS
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});   // {node,parent}
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(parent!=it){    // visited is not a parent but some other node is visted by someone on the same level hence cycle.
                    return true;
                }
            }
            
        }
        return false;
    }

    bool dfsdetect(int node,int parent,vector<int>& vis,vector<int> adj[]){     // DFS
        vis[node]=1;
        
        for(auto it: adj[node]){
            
            if(vis[it]){
                if(it!=parent) return true;
            }
            else if(dfsdetect(it,node,vis,adj)==true){
                return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends