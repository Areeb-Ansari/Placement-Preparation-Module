class Solution {
private:
    int solveRec(vector<int>& nums, int curr, int prev){
        int n = nums.size();
        //base case
        if(curr == n)
            return 0;
        
        int incl = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            incl = 1 + solveRec(nums, curr+1, curr);
        int excl = solveRec(nums, curr+1, prev);
        
        return max(incl, excl);
    }
    
    int solveMem(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        int n = nums.size();
        //base case
        if(curr == n)
            return 0;
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int incl = 0;
        if(prev == -1 || nums[curr] > nums[prev])
            incl = 1 + solveMem(nums, curr+1, curr, dp);
        int excl = solveMem(nums, curr+1, prev, dp);
        
        return dp[curr][prev+1] =  max(incl, excl);
    }
    
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                
                int incl = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                    incl = 1 + dp[curr+1][curr+1];
                int excl = dp[curr+1][prev+1];

                dp[curr][prev+1] =  max(incl, excl);
            }
        }
        return dp[0][0];
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solveRec(nums, 0, -1);
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solveMem(nums, 0, -1, dp);
        
        return solveTab(nums);
    }
};