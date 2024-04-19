class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& vis){
        // i represents the node
        vis[i] = true;
        for(int j=0; j<isConnected[0].size(); j++){
            if(!vis[j] && isConnected[i][j] == 1){
                dfs(j, isConnected, vis);
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool>vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis); // i is the node
            }
        }
        return ans;
    }
};