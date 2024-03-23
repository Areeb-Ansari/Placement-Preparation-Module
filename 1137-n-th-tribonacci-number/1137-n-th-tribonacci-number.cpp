class Solution {
private:
    int solveRec(int n){
        if(n == 0) return 0;
        if(n==1 || n==2) return 1;
        return solveRec(n-1) + solveRec(n-2) + solveRec(n-3);
    }

    int solveMem(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n==1 || n==2) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp) + solveMem(n-3,dp);
        return dp[n];
    }

    int solveTab(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }

    int solveSpace(int n){
        if(n==0) return 0;
        int prev1 = 1;
        int prev2 = 1;
        int prev3 = 0;

        for(int i=3; i<=n; i++){
            int trib = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = trib;
        }
        return prev1;
    }
public:
    int tribonacci(int n) {
        //return solveRec(n);

        // vector<int>dp(n+1,-1);
        // return solveMem(n,dp);

        //return solveTab(n);

        return solveSpace(n);
    }
};