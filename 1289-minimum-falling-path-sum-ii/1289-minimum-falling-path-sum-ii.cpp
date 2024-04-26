class Solution {
public:
    int solveMem(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        if (r < 0 || r >= n || c < 0 || c >= n) return INT_MAX;
        if(r == n-1) return grid[r][c];

        if (dp[r][c] != -1) return dp[r][c];

        int res = INT_MAX;
        for(int nextcol=0; nextcol<n; nextcol++){
            if(c != nextcol){
                res = min(res, grid[r][c] + solveMem(r+1, nextcol, grid, dp));
            }
            
        }
        dp[r][c] = res;
        return dp[r][c];
    }
    int solveTab(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>>dp(n, vector<int>(n,0));

        for(int j=0; j<n; j++){
            dp[0][j] = grid[0][j]; 
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = grid[i][j];

                int mval = INT_MAX;
                for(int k=0; k<n; k++){
                    if(j != k){
                        mval = min(mval, dp[i-1][k]);
                    }
                }
                dp[i][j] += mval;
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        // solution - 1 gets TLE 
        // int n = grid.size();
        // int ans = INT_MAX;
        // for(int c=0; c<n; c++){
        //     vector<vector<int>> dp(n, vector<int>(n,-1));
        //     ans = min(ans, solveMem(0, c, grid, dp));
        // }
        // return ans;

        return solveTab(grid);
    }
};