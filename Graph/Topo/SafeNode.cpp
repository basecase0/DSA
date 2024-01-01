class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];  // reverse adj list
        vector<int>indegree(n);

        for(int i=0;i<n;i++){
            // i->it
            // it->i
            for(int it=0;it<graph[i].size();it++){
                adj[graph[i][it]].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>topo;
        queue<int>q;

        for(int i=0;i<n;i++){
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
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};