class Solution {
public:
    int solveMem(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        if(text1[i] == text2[j]){
            return 1 + solveMem(text1, text2, i-1, j-1, dp);
        }
        else{
            return dp[i][j] = max(solveMem(text1, text2, i-1, j, dp), solveMem(text1, text2, i, j-1, dp));
        }
    }
    int solveTab(string& text1, string& text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0)); // coz  i am treating everything thing as +1

        // for(int i=0; i<=n; i++) dp[i][0] = 0;
        // for(int j=0; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return solveMem(text1, text2, n-1, m-1, dp);

        return solveTab(text1, text2);
    }
};