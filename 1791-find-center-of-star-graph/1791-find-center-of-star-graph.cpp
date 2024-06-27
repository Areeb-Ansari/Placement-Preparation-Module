class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //sol 1
        // unordered_map<int, vector<int>> adj;

        // for(auto edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // for(auto x : adj){
        //     if(x.second.size() > 1) return x.first;
        // }
        // return 0;

        //sol 2
        if((edges[0][0] == edges[1][0]) || (edges[0][0] == edges[1][1])) return edges[0][0];
        else return edges[0][1];
    }
};