class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        if(vis[node]) return;

        vis[node] = true;

        for(auto x : adj[node]){
            if(!vis[x]){
                dfs(x, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>adj;
        vector<bool>vis(n, false);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(source, adj, vis);
        return vis[destination];
    }
};