class Solution {
public:
    void dfs(string src, string& dest, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& vis, double& res, double temp){
        if(vis.count(src)) return;

        vis.insert(src);
        if(src == dest){
            res = temp;
            return;
        }

        for(auto nei : adj[src]){
            dfs(nei.first, dest, adj, vis, res, temp * nei.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        unordered_map<string, vector<pair<string, double>>>adj;

        int i=0;
        for(auto eq : equations){
            string u = eq[0];
            string v = eq[1];

            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0/values[i]});
            i++;
        }

        for(auto query : queries){
            string u = query[0];
            string v = query[1];

            if(!adj.count(u) || !adj.count(v)){
                ans.push_back(-1.0);
            }
            else{
                unordered_set<string>vis;
                double res = -1, temp = 1.0;
                dfs(u, v, adj, vis, res, temp);
                ans.push_back(res);
            }
        }
        return ans;
    }
};