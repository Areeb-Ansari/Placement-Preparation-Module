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
    
    bool solveTab(int n, vector<int>nums, int target){
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        //analysis of base case
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        
        for(int index=n-1; index>=0; index--){
            for(int tar=0; tar<=target; tar++){
                
                bool incl = 0;
                if(tar-nums[index]>=0)
                incl = dp[index+1][tar-nums[index]]; // startinf from n-1 so make dp array of n+1size
                bool excl = dp[index+1][tar]; // to avoid invalid index 

                dp[index][tar] = incl or excl;
                
            }
        }
        return dp[0][target];
    }
    
    bool solveSpace(int n, vector<int>nums, int target){
        vector<int>curr(target+1, 0);
        vector<int>next(target+1, 0);
        
        //analysis of base case
        
            next[0] = 1;
        
        
        for(int index=n-1; index>=0; index--){
            for(int tar=0; tar<=target; tar++){
                
                bool incl = 0;
                if(tar-nums[index]>=0)
                incl = next[tar-nums[index]]; // startinf from n-1 so make dp array of n+1size
                bool excl = next[tar]; // to avoid invalid index 

                curr[tar] = incl or excl;
                
            }
            next = curr;
        }
        return curr[target];
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
        
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solveMem(0, n, nums, target, dp);
        
        //return solveTab(n, nums, target);
        
        return solveSpace(n, nums, target);
        
    }
};