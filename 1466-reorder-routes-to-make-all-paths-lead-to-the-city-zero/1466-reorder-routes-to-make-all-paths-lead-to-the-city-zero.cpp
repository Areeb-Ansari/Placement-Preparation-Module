class Solution {
public:
    int ans;
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& vis){
        if(vis[abs(node)]) return;
        vis[abs(node)] = true;

        for(auto e : adj[node]){
            if(!vis[abs(e)]){
                if(e>0) ans++;
                dfs(abs(e), adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
        unordered_map<int, vector<int>> adj;
        vector<bool>vis(n, false);

        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(-u);
        }

        dfs(0, adj, vis);
        return ans;
    }
};