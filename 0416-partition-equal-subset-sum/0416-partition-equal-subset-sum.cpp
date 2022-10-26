class Solution {
private:
    bool solveRec(int index, int n, vector<int>& nums, int target){
        //base case
        if(index >= n)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        bool incl = solveRec(index+1, n, nums, target-nums[index]);
        bool excl = solveRec(index+1, n, nums, target);
        
        return incl or excl;
    }
    
    bool solveMem(int index, int n, vector<int>& nums, int target, vector<vector<int>>& dp){
        //base case
        if(index >= n)
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool incl = solveMem(index+1, n, nums, target-nums[index], dp);
        bool excl = solveMem(index+1, n, nums, target, dp);
        
        return dp[index][target] = incl or excl;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        if(sum%2 != 0)
            return 0;
        
        int target = sum/2;
        
        //return solveRec(0, n, nums, target);
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solveMem(0, n, nums, target, dp);
    }
};