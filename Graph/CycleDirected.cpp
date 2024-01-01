#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfscheck(int node,int V,int vis[],int pathvis[],vector<int>adj[]){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfscheck(it,V,vis,pathvis,adj)) return true;
            }
            else if(pathvis[it]==true){    // adj node previously visited on same path. CYCLE
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // DFS   vis,pathvis.
        int vis[V]={0};
        int pathvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfscheck(i,V,vis,pathvis,adj)){
                    return true;
                }
            }
        }
        return false;
    }

    // Using BFS (kahn's algo topo)
    bool isCyclic(int V, vector<int> adj[]) {
        // BFS
        vector<int>indegree(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(topo.size()==V) return false;    // topo possible hence no cycle (DAG)
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends