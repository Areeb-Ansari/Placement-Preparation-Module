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
    
    int solveTab(vector<int>& slices){
        int k = slices.size();
        
        vector<vector<int>>dp1(k+2,vector<int>(k+2, 0));
        vector<vector<int>>dp2(k+2,vector<int>(k+2, 0));
        
        //for case 1
        for(int index=k-2; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int eat = slices[index] + dp1[index+2][n-1];
                int noteat = 0 + dp1[index+1][n];

                dp1[index][n] =  max(eat, noteat);
            }
        }
        int case1 = dp1[0][k/3];
        
        //for case 2
        for(int index=k-1; index>=0; index--){
            for(int n=1; n<=k/3; n++){
                int eat = slices[index] + dp2[index+2][n-1];
                int noteat = 0 + dp2[index+1][n];

                dp2[index][n] =  max(eat, noteat);
            }
        }
        int case2 = dp2[1][k/3];
        
        return max(case1, case2);
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
        // int case1 = solveRec(slices, 0, k/3, k-2);
        // int case2 = solveRec(slices, 1, k/3, k-1);
        // return max(case1, case2);
        
        // vector<vector<int>>dp1(k,vector<int>(k, -1));
        // int case1 = solveMem(slices, 0, k/3, k-2, dp1);
        // vector<vector<int>>dp2(k,vector<int>(k, -1));
        // int case2 = solveMem(slices, 1, k/3, k-1, dp2);
        // return max(case1, case2);
        
        return solveTab(slices);
        
        
    }
};