class Solution {
public:
    int solveMem(string ring, string key, int r, int k, vector<vector<int>>& dp){
        if(k == key.size()) return 0;

        if(dp[r][k] != -1) return dp[r][k];

        int res = INT_MAX;
        int mindist;
        int n = ring.size();
        for(int i=0; i<n; i++){
            if(ring[i] == key[k]){
                mindist = min(abs(r-i), n - abs(r-i)); // min(straight dist, moving from last then coming)
                res = min(res, mindist+1+solveMem(ring, key, i, k+1, dp));
            }
        }
        return dp[r][k] = res;
    }
    int findRotateSteps(string ring, string key) {
        // vector<vector<int>>dp(ring.size(), vector<int>(key.size(), -1));
        // return solveMem(ring, key, 0, 0, dp);

        int n = ring.size();
        vector<int>dp(n);

        for(int k=key.size()-1; k>=0; k--){
            vector<int>next(n, INT_MAX);
            for(int r=0; r<n; r++){
                for(int i=0; i<n; i++){
                    if(ring[i] == key[k]){
                        int mindist = min(abs(r-i), n - abs(r-i));
                        next[r] = min(next[r], mindist+1+dp[i]);
                    }
                }
            }
            dp = next;

        }
        return dp[0];
    }
};