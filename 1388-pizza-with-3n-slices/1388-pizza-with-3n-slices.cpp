class Solution {
private:
    int solveRec(vector<int>& slices, int index, int n, int endIndex){
        // base case
        if(n == 0 || index>endIndex)
            return 0;
        
        int eat = slices[index] + solveRec(slices, index+2, n-1, endIndex);
        int noteat = 0 + solveRec(slices, index+1, n, endIndex);
        
        return max(eat, noteat);
    }
    
    int solveMem(vector<int>& slices, int index, int n, int endIndex, vector<vector<int>>& dp){
        // base case
        if(n == 0 || index>endIndex)
            return 0;
        
        if(dp[index][n] != -1)
            return dp[index][n];
        
        int eat = slices[index] + solveMem(slices, index+2, n-1, endIndex, dp);
        int noteat = 0 + solveMem(slices, index+1, n, endIndex, dp);
        
        return dp[index][n] =  max(eat, noteat);
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        // int case1 = solveRec(slices, 0, k/3, k-2);
        // int case2 = solveRec(slices, 1, k/3, k-1);
        // return max(case1, case2);
        
        vector<vector<int>>dp1(k,vector<int>(k, -1));
        int case1 = solveMem(slices, 0, k/3, k-2, dp1);
        vector<vector<int>>dp2(k,vector<int>(k, -1));
        int case2 = solveMem(slices, 1, k/3, k-1, dp2);
        return max(case1, case2);
        
    }
};