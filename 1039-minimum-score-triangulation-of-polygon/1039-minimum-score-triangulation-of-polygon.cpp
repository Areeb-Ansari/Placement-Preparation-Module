class Solution {
private:
    int solveRec(vector<int>& v, int i, int j){
        // base case
        if(i+1 == j)
            return 0;
        
        int ans = INT_MAX; 
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solveRec(v,i,k) + solveRec(v,k,j));
        }
        return ans;
    }
    
    int solveMem(vector<int>& v, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i+1 == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX; 
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v,i,k,dp) + solveMem(v,k,j,dp));
        }
        return dp[i][j] = ans;
    }
    
public:
    int minScoreTriangulation(vector<int>& values) {
         int n = values.size();
        // return solveRec(values, 0, n-1); //i,j
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solveMem(values, 0, n-1, dp);
    }
};