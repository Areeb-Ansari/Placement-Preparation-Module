class Solution {
private:
    int solveRec(vector<vector<char>>& mat, int i, int j, int &maxi){
        //base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        int right = solveRec(mat, i, j+1, maxi);
        int diag = solveRec(mat, i+1, j+1, maxi);
        int down = solveRec(mat, i+1, j, maxi);
        
        if(mat[i][j] == '1'){
            int ans = 1 + min(right,min(diag,down));
            maxi = max(maxi,ans);
            return ans;
        }
        else
            return 0;
    }
    
    int solveMem(vector<vector<char>>& mat, int i, int j, int &maxi,vector<vector<int>>& dp){
        //base case
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diag = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        if(mat[i][j] == '1'){
            dp[i][j] = 1 + min(right,min(diag,down));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else
            return dp[i][j] = 0;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // int maxi = 0;
        // solveRec(matrix, 0, 0, maxi); //i,j
        // return maxi*maxi;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi = 0;
        solveMem(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
        
    }
};