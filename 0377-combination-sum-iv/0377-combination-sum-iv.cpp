class Solution {
private:
    int solveRec(vector<int>& nums, int t){
        //base case
        if(t == 0)
            return 1;
        if(t < 0)
            return 0;
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += solveRec(nums, t - nums[i]); 
        }
        return ans;
    }
    
    int solveMem(vector<int>& nums, int t, vector<int>& dp){
        //base case
        if(t == 0)
            return 1;
        if(t < 0)
            return 0;
        
        if(dp[t] != -1)
            return dp[t];
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans += solveMem(nums, t - nums[i], dp); 
        }
        dp[t] = ans;
        return dp[t];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        //return solveRec(nums,target);
        
        int n = nums.size();
        vector<int>dp(target+1, -1);
        return solveMem(nums,target,dp);
    }
};