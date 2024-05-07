class Solution {
public:
    int solveRec(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        int up = solveRec(i-1, j);
        int left = solveRec(i, j-1);

        return up+left;
    }
    int solveMem(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = solveMem(i-1, j, dp);
        int left = solveMem(i, j-1, dp);

        return dp[i][j] = up + left;
    }
    int solveTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int k=0; k<m; k++) dp[k][0] = 1;
        for(int k=0; k<n; k++) dp[0][k] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
    int solveSpace(int m, int n){
        vector<int>up(n, 1);
        vector<int>curr(n, 0);
        curr[0] = 1;

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int top = up[j];
                int left = curr[j-1];
                curr[j] = top+left;
            }
            up = curr;
        }
        return up[n-1];
    }
    int uniquePaths(int m, int n) {
        //return solveRec(m-1,n-1);

        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return solveMem(m-1, n-1, dp);

        //return solveTab(m,n);
        return solveSpace(m,n);
    }
};