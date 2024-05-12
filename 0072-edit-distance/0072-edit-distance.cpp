class Solution {
public:
    // int solveMem(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
    //     if(i == word1.size()) return word2.size()-j;
    //     if(j == word2.size()) return word1.size()-i;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans = 0;
    //     if(word1[i] == word2[j]){
    //         return solveMem(word1, word2, i+1, j+1, dp);
    //     }
    //     else{
    //         int insert = 1+ solveMem(word1, word2, i, j+1, dp);
    //         int del = 1+ solveMem(word1, word2, i+1, j, dp);
    //         int replace = 1+ solveMem(word1, word2, i+1, j+1, dp);

    //         ans = min(insert, min(del, replace));
    //     }
    //     return dp[i][j] = ans;

    // }
    int solveTab(string& word1, string& word2){
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        //base case analysis
        for(int j=0; j<m; j++) dp[n][j] = m-j;
        for(int i=0; i<n; i++) dp[i][m] = n-i;

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insert = 1+ dp[i][j+1];
                    int del = 1+ dp[i+1][j];
                    int replace = 1+ dp[i+1][j+1];

                    ans = min(insert, min(del, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int solveSpace(string& word1, string& word2){
        int n = word1.size();
        int m = word2.size();
        if(n==0) return m;
        if(m==0) return n;

        vector<int>curr(m+1,0);
        vector<int>prev(m+1,0);

        // base case 
        for(int j=0; j<m; j++) prev[j] = m-j;
        

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                curr[m] = n-i; // base case

                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = prev[j+1];
                }
                else{
                    int insert = 1+ curr[j+1];
                    int del = 1+ prev[j];
                    int replace = 1+ prev[j+1];

                    ans = min(insert, min(del, replace));
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[0];
    }
    int minDistance(string word1, string word2) {
        // int n = word1.size();
        // int m = word2.size();

        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return solveMem(word1, word2, 0, 0, dp);

        //return solveTab(word1, word2);

        return solveSpace(word1, word2);
    }
};